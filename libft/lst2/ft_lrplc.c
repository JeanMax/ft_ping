/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lrplc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 05:03:09 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/24 14:13:47 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** remplace l'élément old par new
** l'élément old n'est pas supprimé, mais retiré de la liste
*/

#include "libft.h"

void	ft_lrplc(t_lst *old, t_lst *new)
{
	if (!old || !new)
		return ;
	new->next = old->next;
	new->prev = old->prev;
	if (old->prev != NULL)
		old->prev->next = new;
	if (old->next != NULL)
		old->next->prev = new;
	old->next = NULL;
	old->prev = NULL;
}
