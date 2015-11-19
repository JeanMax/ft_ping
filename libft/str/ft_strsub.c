/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:43:10 by mcanal            #+#    #+#             */
/*   Updated: 2014/12/14 19:43:26 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Assign (with malloc (3)) and returns the fresh copy of a section of the
** character string given in parameter. The section begins in the index
** "start" and has for length "len". If "start" and "len" does not indicate
** a section of valid string, the behavior is indefinite. If the allocation
** fails, the function returns NULL.
*/

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (!s)
		return (NULL);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (start + len > ft_strlen(s))
		if (start <= ft_strlen(s))
			len = ft_strlen(s) - start;
	str = ft_strncpy(str, s + start, len);
	return (str);
}
