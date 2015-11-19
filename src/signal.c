/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_signal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 04:34:21 by mcanal            #+#    #+#             */
/*   Updated: 2015/11/19 15:13:04 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the place to handle signals of course!
*/

#include "ft_ping.h"

static void		sig_handl(int i)
{
	if (i == SIGBUS)
		error(BUS, NULL);
	else if (i == SIGSEGV)
		error(SEG, NULL);
	else if (i == SIGFPE)
		error(FPE, NULL);
	else if (i == SIGINT)
	{
		//TODO: print stats
		exit(EXIT_SUCCESS);
	}
}

void			sig_init(void)
{
	signal(SIGINT, sig_handl);
	signal(SIGFPE, sig_handl);
	signal(SIGSEGV, sig_handl);
	signal(SIGBUS, sig_handl);
}
