/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:44:56 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 19:51:03 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Assign (with malloc (3)) and returns a copy of the given string
** without the white spaces at the beginning and at the end of this string.
** We consider as white spaces the characters ' ', '\n' and '\t'.
** If s does not contain white spaces at the beginning or at the end,
** the function returns a copy of s. If the allocation fails, the function
** returns NULL.
*/

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	char	*swap;

	if (!s)
		return (NULL);
	while (*s && (ft_isblank(*s) || *s == '\n'))
		s++;
	if (!*s)
		return (ft_strnew(1));
	len = ft_strlen(s) - 1;
	while (*s && (ft_isblank(s[len]) || s[len] == '\n'))
		len--;
	swap = ft_strnew(len);
	if (!swap)
		return (NULL);
	swap = ft_strncpy(swap, s, len + 1);
	swap[len + 1] = '\0';
	return (swap);
}
