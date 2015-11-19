/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:19:53 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 23:18:07 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The atoi() function converts the initial portion of the string  pointed
** to by nptr to int.
*/

#include "libft.h"

static int		count_digit(char *str)
{
	char	*tmp;

	if (!str)
		return (FALSE);
	tmp = str;
	while (*tmp && ft_isdigit(*tmp))
		tmp++;
	return (int)(tmp - str);
}

int				ft_atoi(char *str)
{
	int		sign;
	int		num;

	sign = -1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str == '0')
		str++;
	if (count_digit(str) > 10)
		return (sign);
	num = 0;
	while (*str && ft_isdigit(*str))
	{
		num = num * 10 + *str - '0';
		str++;
	}
	if (!sign)
		num = -num;
	return (num);
}
