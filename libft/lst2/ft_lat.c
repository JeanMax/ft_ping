/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 03:35:27 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/22 17:15:29 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Retourne un pointeur sur l'élément à l'indice n, ou NULL si la liste
** contient moins de n élément(s).     (le premier élément a pour indice 1)
** **alst doit contenir l'adresse d’un pointeur sur le premier élément.
*/

#include "libft.h"

t_lst	*ft_lat(t_lst **alst, size_t n)
{
	t_lst	*tmp;

	if (!alst || !n)
		return (NULL);
	tmp = *alst;
	n--;
	while (n-- && tmp->next != NULL)
		tmp = tmp->next;
	if (!tmp)
		return (NULL);
	return (tmp);
}
