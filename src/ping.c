/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:43:47 by mc                #+#    #+#             */
/*   Updated: 2018/09/03 21:46:30 by mc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

int						ping(t_byte flags)
{
	(void)flags;

	if ((g_env.sock = get_sock()) == -1)
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
	if (!inet_ntop(
			g_env.addr_info.ai_family,									\
			&((struct sockaddr_in *)(void *)g_env.addr_info.ai_addr)->sin_addr,	\
			g_env.addr_str,
			INET6_ADDRSTRLEN
		))
		error(INET_NTOP, NULL);

	gettimeofday(&g_env.start_time, NULL);
	sig_init(SEC_TO_USEC(1.)); //TODO
	printf("PING %s (%s) %d(%d) bytes of data.\n",
		   g_env.opt.host, g_env.addr_str, 56, 84); //TODO
	while (42)
		recv_packet();

	return (EXIT_FAILURE);
}
