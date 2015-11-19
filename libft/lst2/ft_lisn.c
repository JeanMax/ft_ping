/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lisn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 23:47:29 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 18:54:25 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** retourne la position de l'élément dans la liste (premier = 1)
** 0 est retourné en cas d'echec
*/

#include "libft.h"

int				ft_lisn(t_lst **alst, t_lst *lst)
{
	t_lst	*tmp;
	int		i;

	if (!alst || !lst)
		return (FALSE);
	if (*alst == lst)
		return (TRUE);
	tmp = *alst;
	i = 2;
	while (tmp->next != NULL && tmp->next != lst)
	{
		tmp = tmp->next;
		i++;
	}
	if (tmp->next != lst)
		return (FALSE);
	return (i);
}
