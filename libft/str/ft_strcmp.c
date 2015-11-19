/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:09:46 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/15 20:54:53 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The  strcmp()  function compares the two strings s1 and s2.  It returns
** an integer less than, equal to, or greater than zero if  s1  is  found,
** respectively, to be less than, to match, or be greater than s2.
*/

#include "libft.h"

int				ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2 && s1++ && s2++)
		;
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
