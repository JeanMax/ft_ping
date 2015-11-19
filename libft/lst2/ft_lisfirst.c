/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lisfirst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 04:32:18 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/22 14:25:35 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Retourne 1 si l'élément courant est le premier élément de la liste, 0 sinon.
*/

#include "libft.h"

int	ft_lisfirst(t_lst **alst)
{
	if (!alst)
		return (FALSE);
	if ((*alst)->prev == NULL)
		return (TRUE);
	return (FALSE);
}
