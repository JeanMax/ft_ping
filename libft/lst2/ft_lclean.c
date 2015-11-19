/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lclean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 04:42:41 by mcanal            #+#    #+#             */
/*   Updated: 2015/01/09 04:52:25 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** free the whole list
*/

#include "libft.h"

void	ft_lclean(t_lst **alst)
{
	t_lst	*to_free;
	t_lst	*tmp;

	to_free = *alst;
	tmp = to_free;
	while (tmp)
	{
		tmp = to_free->next;
		ft_lfree(&to_free);
		to_free = tmp;
	}
}
