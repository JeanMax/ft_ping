/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 15:07:35 by mcanal            #+#    #+#             */
/*   Updated: 2015/11/19 17:34:05 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

static char				*parse_av(char **av, t_char *flags)
{
	if (!(*++av) || **av != '-')
		return (*av && *(av + 1) ? NULL : *av);
	if (*(*av + 1) && !*(*av + 2))
	{
		if (*(*av + 1) == 'v')
			*flags |= FLAG_V;
		else if (*(*av + 1) == 'h')
			*flags |= FLAG_H;
		else
			return (NULL);
	}
	else if (*(*av + 1) && *(*av + 2) && !*(*av + 3))
	{
		if ((*(*av + 1) == 'v' && *(*av + 2) == 'h') ||	\
			(*(*av + 1) == 'h' && *(*av + 2) == 'v'))
			*flags |= (FLAG_V | FLAG_H);
		else
			return (NULL);
	}
	else
		return (NULL);
	return (parse_av(av, flags));
}

int						main(int ac, char **av)
{
	t_char	flags;
	char	*host;
	char	str[INET6_ADDRSTRLEN];
	struct sockaddr_in	sa;

	flags = 0;
	host = NULL;
	if (ac < 2 || ac > 4 || !(host = parse_av(av, &flags)))
		error(USAGE, *av);

	if ((inet_pton(AF_INET, host, &(sa.sin_addr))) <= 0) //AF_INET6 -> IPV6
		error(INET_PTON, NULL);
	
	if (inet_ntop(AF_INET, &(sa.sin_addr), str, INET6_ADDRSTRLEN) == NULL) //AF_INET6 -> IPV6
		error(INET_NTOP, NULL);

	
	 //debug
	ft_debugstr("host", host);
	if ((flags & FLAG_V))
		ft_debugnbr("FLAG V", (int)flags);
	if ((flags & FLAG_H))
		ft_debugnbr("FLAG H", (int)flags);
	ft_debugstr("str", str);
	//debug
	
	return (EXIT_FAILURE);
}
