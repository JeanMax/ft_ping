/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_clr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 23:19:06 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 18:45:13 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Print the char * s on stdout, with colors!
** clr = yellow, blue, red, green, pink, sky, white, (default = grey)
*/

#include "libft.h"
#include <unistd.h>

void			ft_putstr_clr(char *s, char *clr)
{
	if (*clr == 'r')
		write(1, "\033[31;01m", 8);
	else if (*clr == 'g')
		write(1, "\033[32;01m", 8);
	else if (*clr == 'y')
		write(1, "\033[33;01m", 8);
	else if (*clr == 'b')
		write(1, "\033[34;01m", 8);
	else if (*clr == 'p')
		write(1, "\033[35;01m", 8);
	else if (*clr == 's')
		write(1, "\033[36;01m", 8);
	else if (*clr == 'w')
		write(1, "\033[37;01m", 8);
	else
		write(1, "\033[30;01m", 8);
	write(1, s, ft_strlen(s));
	write(1, "\033[0m", 4);
}
