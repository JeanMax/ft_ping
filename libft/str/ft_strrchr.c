/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:45:49 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 19:09:44 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strrchr() function returns a pointer to the last occurrence of  the
** character c in the string s.
*/

#include "libft.h"

char			*ft_strrchr(const char *s, int c)
{
	const char *ret;

	ret = 0;
	while (*s)
	{
		if (*s == (char)c)
			ret = s;
		s++;
	}
	if (*s == (char)c)
		ret = s;
	return ((char *)ret);
}
