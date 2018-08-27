/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:12:13 by mc                #+#    #+#             */
/*   Updated: 2018/08/27 14:13:09 by mc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** general purpose functions
*/

#include "ft_ping.h"


/*
** The  bzero()  function sets the first n bytes of the area starting at s
** to zero (bytes containing '\0').
*/
void			ft_bzero(void *s, size_t n)
{
	char *swap;

	if (n)
	{
		swap = s;
		while (n--)
			*swap++ = 0;
	}
}
