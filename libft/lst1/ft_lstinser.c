/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 04:40:23 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/12 23:17:59 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** insère un élément (new) après l'élément courant (alst).
*/

#include "libft.h"

void	ft_lstinser(t_list **alst, t_list *new)
{
	if (!alst || !new)
		return ;
	new->next = (*alst)->next;
	(*alst)->next = new;
}
