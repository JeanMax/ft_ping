/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:39:11 by mcanal            #+#    #+#             */
/*   Updated: 2015/10/23 17:07:22 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The  memchr()  function  scans  the  initial n bytes of the memory area
** pointed to by s for the first instance of c.  Both c and the  bytes  of
** the memory area pointed to by s are interpreted as unsigned char.
*/

#include "libft.h"

void			*ft_memchr(const void *s, int c, size_t n)
{
	if (!s || !n)
		return (NULL);
	while (n--)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s = (char *)s + 1;
	}
	return (NULL);
}
