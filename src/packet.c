/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 12:30:10 by mc                #+#    #+#             */
/*   Updated: 2018/08/30 13:13:42 by mc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

/*
** Function: checksum
**
** Description:
**    This function calculates the 16-bit one's complement sum
**    of the supplied buffer (ICMP) header
**
*/
static t_word			checksum(t_word *buffer, int size)
{
	t_dword cksum = 0;

	while (size > 1)
	{
		cksum += *buffer++;
		size -= sizeof(t_word);
	}
	if (size)
		cksum += *(t_byte *)buffer;
	cksum = (cksum >> 16) + (cksum & 0xffff);
	cksum += (cksum >>16);
	return (t_word)(~cksum);
}

static int				validate_msg(t_byte *msg)
{
    struct iphdr	*ip = NULL;
    struct icmphdr	*icmp = NULL;
	t_word			check;

    ip = (struct iphdr *)msg;
    icmp = (struct icmphdr *)(msg + ip->ihl * sizeof(t_dword));

    if (icmp->type != ICMP_ECHOREPLY)
    {
        DEBUGF("nonecho type %hhu recvd\n", icmp->type); /* DEBUG */
        return (EXIT_FAILURE);
    }

    if (icmp->un.echo.id != getpid())
    {
        DEBUGF("someone else's packet %xd != %xd\n",
			   icmp->un.echo.id, getpid()); /* DEBUG */
        return (EXIT_FAILURE);
    }

	check = icmp->checksum;
	icmp->checksum = 0;
    if (check != checksum((t_word *)msg, sizeof(t_packet)))
    {
        DEBUGF("checksum failed"); /* DEBUG */
        return (EXIT_FAILURE);
    }

    printf("%zu bytes from %s: icmp_seq=%d ttl=%d time=%.1f ms\n",
		   sizeof(t_packet), g_env.addr_str,
		   icmp->un.echo.sequence, ip->ttl, 42.2); //TODO

    return (EXIT_SUCCESS);
}

int						recv_packet(void)
{
	struct msghdr	msg = {0};
	struct iovec	iov = {0};
	t_byte			iov_base[IOV_BUF_SIZE] = {0};
	struct timeval	timestamp;
	ssize_t			ret;

	msg.msg_name = g_env.addr_info.ai_addr;
	msg.msg_namelen = g_env.addr_info.ai_addrlen;
	msg.msg_iov = &iov;
	msg.msg_iovlen = 1;
	iov.iov_base = &iov_base;
	iov.iov_len = IOV_BUF_SIZE;

	ret = recvmsg(g_env.sock, &msg, 0);
	gettimeofday(&timestamp, NULL);
	if (ret	< 0 || ret != sizeof(t_packet))
	{
		perror("recv");			/* DEBUG */
		return (EXIT_FAILURE);
	}

	return (validate_msg(iov_base));
}

int						send_packet(void)
{
	static t_packet	packet = {{0}, {0}, {0}}; //TODO
	ssize_t			bwrote;

	if (!packet.header.type)
	{
		packet.header.type = ICMP_ECHO;
		packet.header.un.echo.id = getpid();
		ft_memcpy(&packet.data, "zboub", 6);
	}
	packet.header.un.echo.sequence++;  //TODO: reverse endianess?
	gettimeofday(&packet.timestamp, NULL);
	packet.header.checksum = 0;
	packet.header.checksum = checksum((t_word *)&packet, sizeof(packet));

	bwrote = sendto(g_env.sock, &packet, sizeof(packet), 0,
					g_env.addr_info.ai_addr,
					g_env.addr_info.ai_addrlen);
	if (bwrote < 0)
	{
		perror("send");									/* DEBUG */
		printf("\nPacket Sending Failed! (%zd)\n", bwrote); /* DEBUG */
		return (EXIT_FAILURE);
	}
	if (bwrote < (ssize_t)sizeof(packet))
	{
		printf("Wrote %zd/%zu bytes\n", bwrote, sizeof(packet)); /* DEBUG */
	}

	return (EXIT_SUCCESS);
}
