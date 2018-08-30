/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:12:13 by mc                #+#    #+#             */
/*   Updated: 2018/08/30 19:05:07 by mc               ###   ########.fr       */
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

/*
** The  memcpy()  function  copies  n bytes from memory area src to memory
** area dest.  The memory areas must not overlap.  Use memmove(3)  if  the
** memory areas do overlap.
*/
void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dswap;
	const char	*sswap;

	dswap = dest;
	sswap = src;
	if (dest != src)
		while (n--)
			*dswap++ = *sswap++;
	return (dest);
}

/*
** The  memcmp()  function compares the first n bytes (each interpreted as
** unsigned char) of the memory areas s1 and s2.
*/
int				ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *swap1;
	const unsigned char *swap2;

	if (s1 != s2 && n)
	{
		swap1 = (const unsigned char *)s1;
		swap2 = (const unsigned char *)s2;
		while (n--)
		{
			if (*swap1 != *swap2)
				return (*swap1 - *swap2);
			swap1++;
			swap2++;
		}
	}
	return (0);
}
