/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 19:39:48 by mcanal            #+#    #+#             */
/*   Updated: 2018/08/27 13:33:47 by mc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** error handling
*/

#include "ft_ping.h"

void			error(enum e_error e, char *msg)
{
	if (e == MALLOC)
		fprintf(stderr, "Malloc failed with var: %s\n", msg);
	else if (e == INET_NTOP)
		fprintf(stderr, "inet_ntop failed.\n");
	else if (e == INET_PTON)
		fprintf(stderr, "inet_pton failed.\n");
	else if (e == ADDRINFO)
		fprintf(stderr, "getaddrinfo failed.\n");
	else if (e == SOCKET)
		fprintf(stderr, "socket failed.\n");
	else if (e == USAGE)
		fprintf(stderr, "Usage: %s [-vh] destination\n", msg);
	exit(EXIT_FAILURE);
}
