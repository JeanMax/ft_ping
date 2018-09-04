/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 12:27:55 by mc                #+#    #+#             */
/*   Updated: 2018/09/04 15:21:07 by mc               ###   ########.fr       */
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

int						get_sock(void)
{
	struct addrinfo hints = {0};
	struct addrinfo *result;
	int	sock;

	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_RAW;
	hints.ai_protocol = IPPROTO_ICMP;

	if (getaddrinfo(g_env.opt.host, NULL, &hints, &result))
		error(ADDRINFO, NULL);

	sock = socks_loop(result);

	// setting timeout of recv setting
	/* struct timeval tv_out; */
    /* tv_out.tv_sec = RECV_TIMEOUT; */
    /* tv_out.tv_usec = 0; */
    /* setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, */
	/* 		   (const char*)&tv_out, sizeof tv_out); */


	if (g_env.opt.flags & FLAG_T)
		setsockopt(sock, IPPROTO_IP, IP_TTL,
				   &g_env.opt.ttl, sizeof(g_env.opt.ttl));

	/* freeaddrinfo(result); // not allowed :/ */
	return (sock);
}
