/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:12:13 by mc                #+#    #+#             */
/*   Updated: 2018/08/30 23:50:25 by mc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** general purpose functions
*/

#include "ft_ping.h"


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


/*
** return the difference in miliseconds from 'since' to 'now'
*/
double			time_diff(struct timeval *since, struct timeval *now)
{
	return (double)(now->tv_sec - since->tv_sec) * 1000. \
		+ (double)(now->tv_usec - since->tv_usec) / 1000.;
}
