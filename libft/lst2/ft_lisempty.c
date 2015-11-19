/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lisempty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 03:24:38 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/25 18:12:43 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** renvoie 1 si la liste est vide, 0 si elle contient au moins un élément.
** /!\ still bugged yet
*/

#include "libft.h"

int		ft_lisempty(t_lst **alst)
{
	if (*alst == NULL)
		return (TRUE);
	return (FALSE);
}
