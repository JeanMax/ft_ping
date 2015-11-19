/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:38:44 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 19:48:47 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The memccpy() function copies no more than n bytes from memory area src
** to memory area dest, stopping when the character c is found.
*/

#include "libft.h"

void			*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*dswap;
	const char	*sswap;

	if (n && dest && src)
	{
		dswap = dest;
		sswap = src;
		while (n--)
		{
			if (*sswap == c)
			{
				*dswap++ = *sswap++;
				return (dswap);
			}
			*dswap++ = *sswap++;
		}
	}
	return (NULL);
}
