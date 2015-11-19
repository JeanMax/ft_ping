/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 03:51:51 by mcanal            #+#    #+#             */
/*   Updated: 2015/07/21 01:53:17 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Read all the text in the specified file descriptor and fill a given string.
** Return 0 if fail, else 1.
*/

#include "libft.h"
#include <unistd.h>

int		get_all(int const fd, char **a)
{
	ssize_t	i;
	char	buf[BUFF_SIZE + 1];

	if (!a || fd < 0)
		return (FALSE);
	*a = ft_strnew(1);
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		*a = (char *)ft_realloc(\
			(void *)*a, ft_strlen(*a), ft_strlen(*a) + (size_t)i);
		ft_strcat(*a, buf);
	}
	if (!*a || i < 0)
		return (FALSE);
	return (TRUE);
}
