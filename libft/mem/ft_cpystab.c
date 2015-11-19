/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpystab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 18:57:58 by mcanal            #+#    #+#             */
/*   Updated: 2015/07/12 08:56:24 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Return a copy of a string array.
** If "val" isn't set to NULL, the function will add a string to the array
** with the "val" value.
*/

#include "libft.h"
#include <stdlib.h>

char			**ft_cpystab(char **tab, char *val)
{
	size_t		i;
	char		**new_tab;

	i = 0;
	while (tab[i])
		i++;
	new_tab = malloc((i + (val ? 2 : 1)) * sizeof(char *));
	i = 0;
	while (tab[i])
	{
		new_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	if (val)
		new_tab[i] = ft_strdup(val);
	new_tab[i + (val ? 1 : 0)] = NULL;
	return (new_tab);
}
