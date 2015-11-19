/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:40:10 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 18:56:12 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The  memcpy()  function  copies  n bytes from memory area src to memory
** area dest.  The memory areas must not overlap.  Use memmove(3)  if  the
** memory areas do overlap.
*/

#include "libft.h"

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dswap;
	const char	*sswap;

	dswap = dest;
	sswap = src;
	if (n && dest != src)
	{
		while (n--)
			*dswap++ = *sswap++;
	}
	return (dest);
}
