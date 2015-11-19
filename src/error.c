/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 19:39:48 by mcanal            #+#    #+#             */
/*   Updated: 2015/11/19 17:19:45 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** error handling
*/

#include "ft_ping.h"

static void		error_annex(char e, char *msg)
{
	if (e == MALLOC)
		fail("Malloc failed with var: ");
	failn(msg);
}

void			error(char e, char *msg)
{
	if (e == MALLOC)
		error_annex(e, msg);
	else if (e == BUS)
		failn("Bus error.");
	else if (e == SEG)
		failn("Segmentation fault.");
	else if (e == FPE)
		failn("Floating point exception.");
	else if (e == INET_NTOP)
		failn("inet_ntop failed.");
	else if (e == INET_PTON)
		failn("inet_pton failed.");
	else if (e == USAGE)
	{
		fail("Usage: ");
		fail(msg);
		failn(" [-vh] host");
	}
	exit(EXIT_FAILURE);
}
