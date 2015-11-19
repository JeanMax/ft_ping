/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 05:25:28 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 19:11:23 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** retourne l’adresse du premier élément dont la donnée est
** "égale" à la donnée de référence
*/

#include "libft.h"

t_list			*ft_lstfind(t_list **alst, void *data)
{
	t_list	*tmp;

	if (!alst || !data)
		return (NULL);
	tmp = *alst;
	while (tmp->next != NULL)
	{
		if (!ft_memcmp(tmp->content, data, tmp->content_size))
			return (tmp);
		tmp = tmp->next;
	}
	if (!ft_memcmp(tmp->content, data, tmp->content_size))
		return (tmp);
	return (NULL);
}
