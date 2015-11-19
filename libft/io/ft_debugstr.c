/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debugstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 23:24:49 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 18:42:19 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allows to print a char * variable preceded by its name (debug!)
*/

#include "libft.h"
#include <unistd.h>

void			ft_debugstr(char *name, char *str)
{
	write(1, "\033[31;01m<", 9);
	write(1, name, ft_strlen(name));
	write(1, ":\033[32;01m", 9);
	write(1, str, ft_strlen(str));
	write(1, "\033[31;01m>\033[0m\n", 14);
}
