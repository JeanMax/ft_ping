/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:07:11 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 19:55:21 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Return a line read in a file descriptor.
** The first one parametre is the file descriptor, the second parametre is
** the address of a string which will store the line read on the file
** descriptor. The return value can be 1, 0 or -1 as a line has been read,
** as the reading is done, either that an error happened respectively.
*/

#include "libft.h"
#include <unistd.h>

static int		is_there_line(char *left, char **line)
{
	char	*end;

	if (!left)
		return (FALSE);
	if ((end = ft_strchr(left, '\n')))
	{
		*line = ft_strsub(left, 0, ft_strlen(left) - ft_strlen(end));
		return (TRUE);
	}
	return (FALSE);
}

int				get_next_line(int const fd, char **line)
{
	ssize_t			ret;
	char			buf[BUFF_SIZE + 1];
	static char		*left;

	if (fd < 0 || !line)
		return (-1);
	if (is_there_line(left, line))
	{
		left = ft_strchr(left, '\n') + 1;
		return (1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		left = ft_strjoin(left, buf);
		if (is_there_line(left, line))
		{
			left = ft_strchr(left, '\n') + 1;
			return (1);
		}
	}
	if (!left)
		left = ft_strnew(1);
	*line = ft_strdup(left);
	return (0);
}
