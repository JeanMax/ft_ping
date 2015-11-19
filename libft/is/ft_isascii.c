/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:32:51 by mcanal            #+#    #+#             */
/*   Updated: 2015/07/14 12:57:14 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** checks whether c is a 7-bit unsigned char value that  fits  into
** the ASCII character set.
*/

#include "libft.h"

int		ft_isascii(int i)
{
	if (i >= 0 && i <= 127)
		return (TRUE);
	return (FALSE);
}
