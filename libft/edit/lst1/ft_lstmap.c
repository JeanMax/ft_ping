/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 02:31:48 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 19:48:05 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Parcourt la liste lst en appliquant à chaque maillon la fonction f
** et crée une nouvelle liste “fraiche” avec malloc(3) résultant des
** applications successives. Si une allocation échoue, la fonction renvoie NULL.
*/

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*alist;
	t_list	*new_list;
	t_list	*link;

	if (!lst || !f)
		return (NULL);
	link = f(lst);
	new_list = ft_lstnew(link->content, link->content_size);
	if (!new_list)
		return (NULL);
	alist = new_list;
	while (lst->next != NULL)
	{
		link = f(lst->next);
		new_list->next = ft_lstnew(link->content, link->content_size);
		if (new_list->next == NULL)
			return (NULL);
		new_list = new_list->next;
		lst = lst->next;
	}
	return (alist);
}
