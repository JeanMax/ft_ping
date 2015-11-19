/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstisempty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 03:24:38 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/12 16:41:25 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** renvoie 1 si la liste est vide, 0 si elle contient au moins un élément.
*/

#include "libft.h"

int		ft_lstisempty(t_list **alst)
{
	if (*alst == NULL)
		return (TRUE);
	return (FALSE);
}
