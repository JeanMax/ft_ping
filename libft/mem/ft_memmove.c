/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:40:44 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 18:55:37 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The  memmove()  function  copies n bytes from memory area src to memory
** area dest.  The memory areas may overlap: copying takes place as though
** the  bytes in src are first copied into a temporary array that does not
** overlap src or dest, and the bytes are then copied from  the  temporary
** array to dest.
*/

#include "libft.h"

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d_swap;
	const char	*s_swap;

	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	d_swap = (char *)dest + n;
	s_swap = (char *)src + n;
	while (n)
	{
		d_swap--;
		s_swap--;
		n--;
		*d_swap = *s_swap;
	}
	return (dest);
}
