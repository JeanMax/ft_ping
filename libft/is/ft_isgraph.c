/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isgraph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 04:10:53 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 18:46:40 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** checks for any printable character except space.
*/

#include "libft.h"

int				ft_isgraph(int c)
{
	if (c >= 33 && c <= 126)
		return (TRUE);
	return (FALSE);
}
