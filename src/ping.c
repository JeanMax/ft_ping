/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:43:47 by mc                #+#    #+#             */
/*   Updated: 2018/08/29 12:48:42 by mc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"


static void				print_header(char *host)
{
	char	addr_buf[INET6_ADDRSTRLEN];

	if (!inet_ntop(
			g_env.addr_info.ai_family,									\
			&((struct sockaddr_in *)(void *)g_env.addr_info.ai_addr)->sin_addr,	\
			addr_buf,													\
			INET6_ADDRSTRLEN
		))
		error(INET_NTOP, NULL);
	printf("PING %s (%s) %d(%d) bytes of data.\n", host, addr_buf, 56, 84); //TODO
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
		error(IPV6, NULL);

	print_header(host);
	send_packet(sock);
	recv_packet(sock);

	return (EXIT_FAILURE);
}
