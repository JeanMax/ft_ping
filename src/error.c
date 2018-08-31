/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 19:39:48 by mcanal            #+#    #+#             */
/*   Updated: 2018/08/30 23:53:22 by mc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** error handling
*/

#include "ft_ping.h"

void			error(enum e_error e, char *msg)
{
	if (e == USAGE)
		fprintf(stderr, "Usage: %s [-vh] destination\n", msg);
	else if (e == ROOT)
		fprintf(stderr, "%s must be run with root privileges.\n", msg);
	else if (e == INET_NTOP)
		fprintf(stderr, "inet_ntop failed.\n");
	else if (e == ADDRINFO)
		fprintf(stderr, "getaddrinfo failed.\n");
	else if (e == SOCKET)
		fprintf(stderr, "socket failed.\n");
	else if (e == IPV6)
		fprintf(stderr, "IPv6 protocol is not implemented.\n");

	exit(EXIT_FAILURE);
}
