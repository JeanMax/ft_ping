/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 19:39:48 by mcanal            #+#    #+#             */
/*   Updated: 2018/09/06 16:46:09 by vm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** error handling
*/

#include "ft_ping.h"

void			error(enum e_error e, char *msg)
{
	if (e == USAGE)
		fprintf(stderr, "Usage: %s [-Dfhqv]"
				" [-c count]"
				" [-i interval]"
				" [-t ttl]"
				" [-w deadline]"
				" destination\n", msg);
	else if (e == ROOT)
		fprintf(stderr, "%s must be run with root privileges.\n", msg);
	else if (e == INET_NTOP)
		fprintf(stderr, "inet_ntop failed.\n");
	else if (e == ADDRINFO)
		fprintf(stderr, "./ft_ping: %s: Name or service not known.\n", msg);
	else if (e == SOCKET)
		fprintf(stderr, "socket failed.\n");
	else if (e == IPV6)
		fprintf(stderr, "IPv6 protocol is not implemented.\n");
	else if (e == TIMER)
		fprintf(stderr, "setitimer failed.\n");
	else if (e == SEND)
		fprintf(stderr, "connect: Network is unreachable.\n");

	exit(PING_ERROR);
}
