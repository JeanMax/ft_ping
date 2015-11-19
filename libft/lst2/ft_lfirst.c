/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfirst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 03:58:41 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 18:54:05 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** retourne un pointeur sur le premier élément de la liste
*/

#include "libft.h"

t_lst			*ft_lfirst(t_lst **alst)
{
	t_lst	*tmp;

	if (!alst)
		return (NULL);
	tmp = *alst;
	while (tmp->prev != NULL)
		tmp = tmp->prev;
	return (tmp);
}
