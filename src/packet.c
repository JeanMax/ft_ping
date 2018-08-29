/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 12:30:10 by mc                #+#    #+#             */
/*   Updated: 2018/08/29 12:36:04 by mc               ###   ########.fr       */
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

int						send_packet(int sock)
{
	static t_packet	packet = {{0}, {0}, {0}};
	ssize_t			bwrote;

	if (!packet.header.type)
	{
		packet.header.type = ICMP_ECHO;
		packet.header.un.echo.id = (t_word)getpid(); //TODO: reverse endianess?
		ft_memcpy(&packet.data, "zboub", 6);
	}
	packet.header.un.echo.sequence++;  //TODO: reverse endianess?
	gettimeofday(&packet.timestamp, NULL);
	packet.header.checksum = 0;
	packet.header.checksum = checksum((t_word *)&packet, sizeof(packet));

	bwrote = sendto(sock, &packet, sizeof(packet), 0,
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

int						recv_packet(int sock)
{
	(void)sock;
	return 42;
}
