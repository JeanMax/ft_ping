/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 15:07:35 by mcanal            #+#    #+#             */
/*   Updated: 2015/11/20 16:29:12 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"


static t_bool			parse_flags(char *s, t_char *flags)
{
	if (!*s)
		return (TRUE);
	else if (*s == 'v')
		*flags |= FLAG_V;
	else if (*s == 'h')
		*flags |= FLAG_H;
	else
		return (FALSE);	

	return (parse_flags(s + 1, flags));
}

static char				*parse_av(char **av, t_char *flags)
{
	if (!(*av) || **av != '-')
		return (*av && *(av + 1) ? NULL : *av);

	if (!(parse_flags(*av + 1, flags)))
		return (NULL);

	return (parse_av(av + 1, flags));
}

int						main(int ac, char **av)
{
	t_char	flags;
	char	*host;
	char	str[INET6_ADDRSTRLEN];
	struct sockaddr_in	sa;

	flags = 0;
	host = NULL;
	if (ac < 2 || ac > 4 || !(host = parse_av(av + 1, &flags)))
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
