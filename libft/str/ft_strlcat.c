/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:41:46 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 19:03:41 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The `ft_strlcat()` function concatenates the null-terminated string `src`
** into the null-terminated string `dst`. The `size` parameter represents a
** buffer size (= big), not a combined strings' size like that of `ft_strncat`.
** If copy cannot occur because buffer's `size` is too small, returns
** `size + ft_strlen(src)`; otherwise, perform the copy and returns final size.
*/

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	char			*dest_swap;
	char			*src_swap;
	size_t			swap_len;
	size_t			dest_len;

	dest_swap = dest;
	src_swap = (char *)src;
	swap_len = size;
	while (swap_len-- && *dest_swap)
		dest_swap++;
	dest_len = (size_t)(dest_swap - dest);
	swap_len = size - dest_len;
	if (swap_len == 0)
		return (dest_len + ft_strlen(src_swap));
	while (*src_swap)
	{
		if (swap_len != 1)
		{
			*dest_swap++ = *src_swap;
			swap_len--;
		}
		src_swap++;
	}
	*dest_swap = '\0';
	return (dest_len + (size_t)(src_swap - src));
}
