/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 05:46:14 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 18:44:28 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** print a double on stdout
**	 while (swap < 1 && swap != 0)
** this causes a warning and probably some bugs (line 30)
*/

#include "libft.h"

void			ft_putdbl(double nbr)
{
	int		i;
	double	swap;

	ft_putnbr((int)nbr);
	ft_putchar('.');
	nbr -= (int)nbr;
	swap = nbr * 10;
	while (swap < 1)
	{
		ft_putchar('0');
		swap *= 10;
	}
	nbr *= 10000000;
	i = 1;
	while (nbr >= 10000000)
	{
		i *= 10;
		nbr /= 10;
	}
	ft_putnbr((int)nbr % (10000000 / i));
}
