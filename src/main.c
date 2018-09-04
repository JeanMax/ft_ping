/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 15:07:35 by mcanal            #+#    #+#             */
/*   Updated: 2018/09/03 23:07:30 by mc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_env g_env	= {{0}, {0}, {0}, -1, {0}, {0}};


static t_bool			parse_flags(char *s, char *arg, t_byte *flags)
{
	//TODO: -[DO] ?
	if (!*s)
		return (TRUE);
	if (*s == 'h' || *(s + 1))
		return (FALSE);

	if (*s == 'v') //TODO
	{
		*flags |= FLAG_V;
		return (TRUE);
	}

	if (*s == 'q') //TODO
	{
		*flags |= FLAG_Q;
		return (TRUE);
	}

	if (*s == 'f') //TODO
	{
		*flags |= FLAG_F;
		return (TRUE);
	}

	if (*s == 'c')
	{
		*flags |= FLAG_C;
		g_env.opt.npackets = ft_atoi(arg);
		if (g_env.opt.npackets < 1)
		{
			fprintf(stderr, "bad number of packets to transmit.\n");
			return (FALSE);
		}
		return (NEXT_ARG);
	}

	if (*s == 't') //TODO
	{
		*flags |= FLAG_T;
		g_env.opt.ttl = ft_atoi(arg);
		if (g_env.opt.ttl < 0 || g_env.opt.ttl > 255)
		{
			fprintf(stderr, "ttl %u out of range\n", g_env.opt.ttl);
			return (FALSE);
		}
		return (NEXT_ARG);
	}

	if (*s == 'i')
	{
		*flags |= FLAG_I;
		g_env.opt.interval = ft_atoi(arg); //TODO: stod?
		if (g_env.opt.interval < 1)
		{
			fprintf(stderr, "bad timing interval\n");
			return (FALSE);
		}
		return (NEXT_ARG);
	}

	if (*s == 'w')
	{
		*flags |= FLAG_W;
		g_env.opt.deadline = ft_atoi(arg);
		if (g_env.opt.deadline < 0)
		{
			fprintf(stderr, "bad wait time\n");
			return (FALSE);
		}
		return (NEXT_ARG);
	}

	fprintf(stderr, "invalid option -- '%c'\n", *s);
	return (FALSE);
}

static char				*parse_av(char **av, t_byte *flags)
{
	t_bool	ret;

	if (!*av || **av != '-')
		return (*av && *(av + 1) ? NULL : *av);

	if (!(ret = parse_flags(*av + 1, *(av + 1), flags)))
		return (NULL);

	return (parse_av(av + ret, flags));
}

int						main(int ac, char **av)
{
	if (ac < 2 || !(g_env.opt.host = parse_av(av + 1, &g_env.opt.flags)))
		error(USAGE, *av);

	if (getuid() != 0)
		error(ROOT, *av);

	g_env.stats.min_trip_time = 0xffff;

	return (ping());
    /* TODO: exit code */
	/* If ping does not receive any reply packets at all it will exit with code 1.  */
	/* If a packet count and deadline are both specified, and fewer than */
	/* count packets are received by the time the deadline has arrived, it will */
	/* also exit with code 1. On other error it exits with code 2. Otherwise */
	/* it exits with code 0. This makes it possible to use the exit code to see */
	/* if a host is alive or not. */
}
