/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldellink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 23:55:52 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/28 12:56:16 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** retire un élément 'n' de la liste, mais ne le supprime pas!
** l'élément 'n-1' pointera sur l'élément 'n+1'
*/

#include "libft.h"

void	ft_ldellink(t_lst *lst)
{
	if (!lst)
		return ;
	if (lst->prev != NULL)
		lst->prev->next = lst->next;
	if (lst->next != NULL)
		lst->next->prev = lst->prev;
	lst->prev = NULL;
	lst->next = NULL;
}
