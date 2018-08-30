/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 12:27:55 by mc                #+#    #+#             */
/*   Updated: 2018/08/30 19:48:37 by mc               ###   ########.fr       */
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

	if (getaddrinfo(g_env.host, NULL, &hints, &result))
		error(ADDRINFO, NULL);

	sock = socks_loop(result);

	freeaddrinfo(result);
	return (sock);
}
