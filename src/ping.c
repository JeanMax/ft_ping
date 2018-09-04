/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:43:47 by mc                #+#    #+#             */
/*   Updated: 2018/09/03 23:11:00 by mc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

int						ping(void)
{
	if ((g_env.sock = get_sock()) == -1)
		error(SOCKET, NULL);

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
	sig_init(SEC_TO_USEC(g_env.opt.interval) / 1000);
	printf("PING %s (%s) %d(%d) bytes of data.\n",
		   g_env.opt.host, g_env.addr_str, 56, 84); //TODO
	while (42)
		recv_packet();

	return (EXIT_FAILURE);
}
