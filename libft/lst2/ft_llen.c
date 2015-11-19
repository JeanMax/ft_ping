/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 04:25:32 by mcanal            #+#    #+#             */
/*   Updated: 2015/07/12 08:54:03 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** retourne la taille de la liste
*/

#include "libft.h"

int	ft_llen(t_lst **alst)
{
	t_lst	*tmp;
	int		i;

	if (!alst)
		return (FALSE);
	tmp = *alst;
	i = 1;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
