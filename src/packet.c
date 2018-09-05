/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 12:30:10 by mc                #+#    #+#             */
/*   Updated: 2018/09/06 00:41:46 by mc               ###   ########.fr       */
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

static int				validate_msg(t_byte *msg, ssize_t msg_len)
{
    struct iphdr	*ip = NULL;
    struct icmphdr	*icmp = NULL;
	t_word			check;
	struct timeval	now;
	struct timeval	*since;
	double			trip_time;

	gettimeofday(&now, NULL);
    ip = (struct iphdr *)msg;
    icmp = (struct icmphdr *)(msg + ip->ihl * sizeof(t_dword));

	if (icmp->type == ICMP_TIME_EXCEEDED || g_env.stats.n_errors)
	{
		if (!(g_env.opt.flags & FLAG_Q))
			printf("%zu bytes from %s: icmp_seq=%d Time to live exceeded\n",
				   sizeof(t_packet), g_env.addr_str,
				   g_env.stats.n_sent);
		g_env.stats.n_errors++;
        return (EXIT_FAILURE);
	}
    if (icmp->type != ICMP_ECHOREPLY)
    {
        DEBUGF("nonecho type %hhu recvd\n", icmp->type); /* DEBUG */
        return (EXIT_FAILURE);
    }

	if (msg_len != sizeof(t_packet))
	{
        DEBUGF("incomplete packet"); /* DEBUG */
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

	if (ft_memcmp(
			((t_byte *)icmp + sizeof(struct icmphdr) + sizeof(struct timeval)),
			"zboub", 6))
	{
        DEBUGF("msg data corrupted"); /* DEBUG */
        return (EXIT_FAILURE);
	}

	since = (struct timeval *)((t_byte *)icmp + sizeof(struct icmphdr));
	trip_time = (double)time_diff(since, &now) / 1000;
	g_env.stats.n_received++;
	g_env.stats.trip_time_sum += (long double)trip_time;
	g_env.stats.trip_time_sum_squared += (long double)(trip_time * trip_time);
	g_env.stats.max_trip_time = (double)MAX(g_env.stats.max_trip_time, trip_time);
	g_env.stats.min_trip_time = (double)MIN(g_env.stats.min_trip_time, trip_time);

	if (!(g_env.opt.flags & FLAG_Q))
		printf("%zu bytes from %s: icmp_seq=%d ttl=%d time=%.1f ms\n",
			   sizeof(t_packet), g_env.addr_str,
			   icmp->un.echo.sequence, ip->ttl,
			   trip_time);

	if (g_env.opt.flags & FLAG_F)
		putchar('\b');

    return (EXIT_SUCCESS);
}

int						recv_packet(void)
{
	struct msghdr	msg = {0};
	struct iovec	iov = {0};
	t_byte			iov_base[IOV_BUF_SIZE] = {0};
	ssize_t			ret;

	msg.msg_name = g_env.addr_info.ai_addr;
	msg.msg_namelen = g_env.addr_info.ai_addrlen;
	msg.msg_iov = &iov;
	msg.msg_iovlen = 1;
	iov.iov_base = &iov_base;
	iov.iov_len = IOV_BUF_SIZE;

	ret = recvmsg(g_env.sock, &msg, MSG_DONTWAIT);
	if (ret	< 0)
	{
		/* perror("recv");			/\* DEBUG *\/ */
		return (EXIT_FAILURE);
	}

	return (validate_msg(iov_base, ret));
}

int						send_packet(void)
{
	static t_packet	packet = {{0}, {0}, {0}};
	ssize_t			bwrote;

	if (!packet.header.type)
	{
		packet.header.type = ICMP_ECHO;
		packet.header.un.echo.id = (t_word)getpid();
		ft_memcpy(&packet.data, "zboub", 6);
	}
	packet.header.un.echo.sequence++;
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

	if (g_env.opt.flags & FLAG_F)
		putchar('.');
	g_env.stats.n_sent++;
	return (EXIT_SUCCESS);
}
