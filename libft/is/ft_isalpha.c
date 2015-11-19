/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:38:29 by mcanal            #+#    #+#             */
/*   Updated: 2015/03/09 01:44:17 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** checks  for an alphabetic character; in the standard "C" locale,
** it  is  equivalent  to  (isupper(c)  ||  islower(c)).   In  some
** locales,  there may be additional characters for which isalpha()
** is true—letters which are neither upper case nor lower case.
*/

#include "libft.h"

int	ft_isalpha(int i)
{
	if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
		return (TRUE);
	return (FALSE);
}
