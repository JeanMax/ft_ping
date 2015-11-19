/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 15:10:14 by mcanal            #+#    #+#             */
/*   Updated: 2015/07/21 19:57:57 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Assign (with malloc (3)) and returns an array of fresh character strings
** (all ended with one '\0 ', the array also thus) tesulting from the cut of
** s according to the character c. If the allocation fails,
** the function returns NULL.
** Example: ft_strsplit("*what*is***up*", ’*’) returns the array
** ["what", "is", "up"].
*/

#include "libft.h"
#include <stdlib.h>

static size_t	ft_word_nb(char const *s, char c)
{
	size_t	word_nb;

	word_nb = ((*s == c) ? (0) : (1));
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1))
			word_nb++;
		s++;
	}
	return (word_nb);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t	word_len;

	word_len = 0;
	while (*s != c && *s)
	{
		s++;
		word_len++;
	}
	return (word_len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(tab = malloc((ft_word_nb(s, c) + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			if (!(tab[i] = ft_strsub(s, 0, ft_word_len(s, c))))
			{
				ft_freestab(tab);
				return (NULL);
			}
			s += ft_word_len(s, c);
			i++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
