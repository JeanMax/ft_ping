/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 04:34:21 by mcanal            #+#    #+#             */
/*   Updated: 2018/08/27 13:27:09 by mc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the place to handle signals of course!
*/

#include "ft_ping.h"

static void		sig_handl(int i)
{
	if (i == SIGINT)
	{
		//TODO: print stats
		exit(EXIT_SUCCESS);
	}
}

void			sig_init(void)
{
	signal(SIGINT, sig_handl);
}
