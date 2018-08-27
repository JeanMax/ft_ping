/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 15:07:35 by mcanal            #+#    #+#             */
/*   Updated: 2018/08/27 16:09:17 by mc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_env g_env	= {0};


static t_bool			parse_flags(char *s, t_byte *flags)
{
	if (!*s)
		return (TRUE);
	else if (*s == 'v')
		*flags |= FLAG_V;
	else if (*s == 'h')
		return (FALSE);
	else
		return (fprintf(stderr, "invalid option -- '%c'\n", *s) && FALSE);

	return (parse_flags(s + 1, flags));
}

static char				*parse_av(char **av, t_byte *flags)
{
	if (!(*av) || **av != '-')
		return (*av && *(av + 1) ? NULL : *av);

	if (!(parse_flags(*av + 1, flags)))
		return (NULL);

	return (parse_av(av + 1, flags));
}

int						main(int ac, char **av)
{
	char	*host;
	t_byte	flags;

	flags = NO_FLAG;
	host = NULL;
	if (ac < 2 || ac > 4 || !(host = parse_av(av + 1, &flags)))
		error(USAGE, *av);

	if (getuid() != 0)
		error(ROOT, *av);

	return (ping(host, flags));
}
