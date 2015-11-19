/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdbl_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 05:46:14 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/18 06:25:25 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** print a double on specied file descriptor
*/

#include "libft.h"

void			ft_putdbl_fd(double nbr, int fd)
{
	int			i;

	ft_putnbr_fd((int)nbr, fd);
	ft_putchar_fd('.', fd);
	nbr -= (int)nbr;
	nbr *= 10000000;
	i = 1;
	while (nbr >= 10000000)
	{
		i *= 10;
		nbr /= 10;
	}
	ft_putnbr_fd((int)nbr % (10000000 / i), fd);
}
