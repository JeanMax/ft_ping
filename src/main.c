/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 15:07:35 by mcanal            #+#    #+#             */
/*   Updated: 2018/08/31 00:36:03 by mc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_env g_env	= {{0}, {0}, NULL, -1, {0}, {0}};


static t_bool			parse_flags(char *s, t_byte *flags)
{
	//TODO: -[tcwifDO]
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
	t_byte	flags = NO_FLAG;

	if (ac < 2 || ac > 4 || !(g_env.host = parse_av(av + 1, &flags)))
		error(USAGE, *av);

	if (getuid() != 0)
		error(ROOT, *av);

	g_env.stats.min_trip_time = 0xffff;

	return (ping(flags));
    /* TODO: exit code */
	/* If ping does not receive any reply packets at all it will exit with code 1.  */
	/* If a packet count and deadline are both specified, and fewer than */
	/* count packets are received by the time the deadline has arrived, it will */
	/* also exit with code 1. On other error it exits with code 2. Otherwise */
	/* it exits with code 0. This makes it possible to use the exit code to see */
	/* if a host is alive or not. */
}
