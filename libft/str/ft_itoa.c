/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:50:06 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 19:50:40 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Assign (with malloc (3)) and turns(returns) a "fresh" character string
** ended with one '\0 ' representing the integer n given in parameter.
** The negative numbers must be managed. If the allocation fails,
** the function return NULL.
*/

#include "libft.h"

static size_t	length(int n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	int		sign;

	if (n == -2147483647 - 1)
		return ("-2147483648");
	len = length(n);
	sign = 0;
	if (n < 0)
	{
		n = -n;
		sign = 42;
		len++;
	}
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	str[--len] = n % 10 + '0';
	while (n /= 10)
		str[--len] = n % 10 + '0';
	if (sign)
		str[0] = '-';
	return (str);
}
