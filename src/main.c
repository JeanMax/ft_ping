/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 15:07:35 by mcanal            #+#    #+#             */
/*   Updated: 2018/09/06 16:26:59 by vm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_env g_env	= {{0}, {0}, {0}, -1, {0}, {0}};


static t_bool			parse_flags(char *s, char *arg)
{
	if (!*s)
		return (TRUE);
	if (*s == 'h' || *(s + 1))
		return (FALSE);

	if (*s == 'v')
	{
		if ((g_env.opt.flags & FLAG_Q))
		{
			fprintf(stderr, "can't be verbose and quiet at the same time.\n");
			return (FALSE);
		}
		g_env.opt.flags |= FLAG_V;
		return (TRUE);
	}

	if (*s == 'q')
	{
		if ((g_env.opt.flags & FLAG_V))
		{
			fprintf(stderr, "can't be verbose and quiet at the same time.\n");
			return (FALSE);
		}
		g_env.opt.flags |= FLAG_Q;
		return (TRUE);
	}

	if (*s == 'D')
	{
		g_env.opt.flags |= FLAG_D;
		return (TRUE);
	}

	if (*s == 'c')
	{
		g_env.opt.flags |= FLAG_C;
		g_env.opt.n_packets = ft_atoi(arg);
		if (g_env.opt.n_packets < 1 || g_env.opt.n_packets > INT_MAX / 2)
		{
			fprintf(stderr, "bad number of packets to transmit.\n");
			return (FALSE);
		}
		return (NEXT_ARG);
	}

	if (*s == 't')
	{
		g_env.opt.flags |= FLAG_T;
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
		g_env.opt.flags |= FLAG_I;
		g_env.opt.interval = ft_atoi(arg);
		if (g_env.opt.interval < 1 || g_env.opt.interval > INT_MAX / 2)
		{
			fprintf(stderr, "bad timing interval\n");
			return (FALSE);
		}
		return (NEXT_ARG);
	}


	if (*s == 'f')
	{
		if ((g_env.opt.flags & FLAG_V))
		{
			fprintf(stderr, "can't be verbose and quiet at the same time.\n");
			return (FALSE);
		}
		if (!(g_env.opt.flags & FLAG_I))
			g_env.opt.interval = 2;
		g_env.opt.flags |= (FLAG_F | FLAG_Q);
		return (TRUE);
	}

	if (*s == 'w')
	{
		g_env.opt.flags |= FLAG_W;
		g_env.opt.deadline = ft_atoi(arg);
		if (g_env.opt.deadline < 1 || g_env.opt.deadline > INT_MAX / 2)
		{
			fprintf(stderr, "bad wait time\n");
			return (FALSE);
		}
		return (NEXT_ARG);
	}

	fprintf(stderr, "invalid option -- '%c'\n", *s);
	return (FALSE);
}

static char				*parse_av(char **av)
{
	t_bool	ret;

	if (!*av || **av != '-')
		return (*av && *(av + 1) ? NULL : *av);

	if (!(ret = parse_flags(*av + 1, *(av + 1))))
		return (NULL);

	return (parse_av(av + ret));
}

int						main(int ac, char **av)
{
	if (ac < 2 || !(g_env.opt.host = parse_av(av + 1)))
		error(USAGE, *av);

	if (getuid() != 0)
		error(ROOT, *av);

	g_env.stats.min_trip_time = 0xffff;

	return (ping());
}
