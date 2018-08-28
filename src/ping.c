/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:43:47 by mc                #+#    #+#             */
/*   Updated: 2018/08/28 16:43:33 by mc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

static int				socks_loop(struct addrinfo *rp)
{
	int sock;

	if (rp == NULL)
		return (-1);
	sock = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
	if (sock != -1)
	{
		ft_memcpy(&g_env.addr_info, rp, sizeof(struct addrinfo));
		return (sock);
	}
	return (socks_loop(rp->ai_next));
}

static int				get_sock(char *host)
{
	struct addrinfo hints = {0};
	struct addrinfo *result;
	int	sock;

	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_RAW;
	hints.ai_protocol = IPPROTO_ICMP;

	if (getaddrinfo(host, NULL, &hints, &result))
		error(ADDRINFO, NULL);

	sock = socks_loop(result);

	freeaddrinfo(result);
	return (sock);
}

static void				print_header(char *host)
{
	char	addr_buf[INET6_ADDRSTRLEN];

	if (!inet_ntop(
			g_env.addr_info.ai_family,									\
			&((struct sockaddr_in *)(g_env.addr_info.ai_addr))->sin_addr, \
			addr_buf,													\
			INET6_ADDRSTRLEN
		))
		error(INET_NTOP, NULL);
	printf("PING %s (%s) %d(%d) bytes of data.\n", host, addr_buf, 56, 84); //TODO
}

// Function: checksum
//
// Description:
//    This function calculates the 16-bit one's complement sum
//    of the supplied buffer (ICMP) header
//
t_word checksum(t_word *buffer, int size)
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

static int				send_packet(int sock)
{
	static t_packet	packet = {{0}, {0}, {0}};
	ssize_t			bwrote;

	if (!packet.header.type)
	{
		packet.header.type = ICMP_ECHO;
		packet.header.un.echo.id = getpid(); //TODO: reverse endianess?
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

static int				recv_packet(int sock)
{
	(void)sock;
	return 42;
}

int						ping(char *host, t_byte flags)
{
	int sock;
	(void)flags;

	if ((sock = get_sock(host)) == -1)
		error(SOCKET, NULL);

	// setting timeout of recv setting
	/* struct timeval tv_out; */
    /* tv_out.tv_sec = RECV_TIMEOUT; */
    /* tv_out.tv_usec = 0; */
    /* setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, */
	/* 		   (const char*)&tv_out, sizeof tv_out); */

	// set socket options at ip to TTL and value to ttl_val
	/* int ttl_val = 64; */
    /* if (setsockopt(sock, SOL_IP, IP_TTL, */
	/* 			   &ttl_val, sizeof(ttl_val)) != 0) */
    /* { */
    /*     printf("\nSetting socket options to TTL failed!\n"); */
    /*     return (EXIT_FAILURE); */
    /* } */

	if (g_env.addr_info.ai_family == AF_INET6)
	{
		printf("no ipv6 plz\n");	/* DEBUG */
		return EXIT_FAILURE;
	}

	print_header(host);
	send_packet(sock);
	recv_packet(sock);

	return (EXIT_FAILURE);
}
