/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:56:43 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/09 21:22:38 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The  strcat() function appends the src string to the dest string, over‐
** writing the terminating null byte ('\0') at the end of dest,  and  then
** adds  a  terminating  null  byte.  The strings may not overlap, and the
** dest string must have enough space for the  result.
*/

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*swap;

	swap = dest;
	while (*swap)
		swap++;
	while (*src)
		*(swap++) = *(src++);
	*swap = '\0';
	return (dest);
}
