/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 03:58:41 by mcanal            #+#    #+#             */
/*   Updated: 2015/07/21 20:06:45 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Free a char * tab
*/

#include "libft.h"

void	ft_freestab(char **tab)
{
	char	**swap;

	swap = tab;
	while (*tab)
		ft_memdel((void *)(tab++));
	ft_memdel((void *)&swap);
}
