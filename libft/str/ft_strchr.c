/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:41:13 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/15 20:53:07 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The  strchr() function returns a pointer to the first occurrence of the
** character c in the string s.
*/

#include "libft.h"

char			*ft_strchr(const char *s, int i)
{
	while (*s != (char)i)
		if (!*s++)
			return (NULL);
	return ((char *)s);
}
