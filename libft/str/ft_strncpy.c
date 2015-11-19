/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:27:33 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 21:07:01 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The  strncpy()  function is similar, except that at most n bytes of src
** are copied.  Warning: If there is no null byte among the first n  bytes
** of src, the string placed in dest will not be null-terminated.
** If  the  length of src is less than n, strncpy() writes additional null
** bytes to dest to ensure that a total of n bytes are written.
*/

#include "libft.h"

char			*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*swap;

	if (!src)
		return (NULL);
	swap = dest;
	while (n && *src)
	{
		*(dest++) = *(src++);
		n--;
	}
	while (n)
	{
		*(dest++) = 0;
		n--;
	}
	return (swap);
}
