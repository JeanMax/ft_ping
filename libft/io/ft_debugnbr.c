/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debugnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 23:24:49 by mcanal            #+#    #+#             */
/*   Updated: 2015/07/14 23:22:35 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allows to print an int variable preceded by its name (debug!)
*/

#include "libft.h"

void	ft_debugnbr(char *name, int nbr)
{
	ft_putchar_clr('<', "r");
	ft_putstr_clr(name, "r");
	ft_putchar_clr(':', "r");
	ft_putnbr_clr(nbr, "g");
	ft_putendl_clr(">", "r");
}
