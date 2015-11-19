/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:10:42 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 23:13:09 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The  strcpy()  function  copies the string pointed to by src, including
** the terminating null byte ('\0'), to the buffer  pointed  to  by  dest.
** The  strings  may  not overlap, and the destination string dest must be
** large enough to receive the copy.
*/

#include "libft.h"

char			*ft_strcpy(char *dest, const char *src)
{
	char	*swap;

	swap = dest;
	while ((*swap++ = *src++))
		;
	return (dest);
}
