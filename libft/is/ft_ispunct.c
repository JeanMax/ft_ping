/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 04:11:05 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 18:46:54 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** checks  for  any  printable character which is not a space or an
** alphanumeric character.
*/

#include "libft.h"

int				ft_ispunct(int c)
{
	if (c != ' ' && !ft_isalnum(c) && ft_isprint(c))
		return (TRUE);
	return (FALSE);
}
