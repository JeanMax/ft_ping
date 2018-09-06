/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 04:34:21 by mcanal            #+#    #+#             */
/*   Updated: 2018/09/06 15:15:00 by vm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the place to handle signals of course!
*/

#include "ft_ping.h"

void		interupt_handler(int i)
{
	struct timeval	now;
	double			avg = (double)g_env.stats.trip_time_sum
		/ (double)g_env.stats.n_received;

	(void)i;
	gettimeofday(&now, NULL);
	printf("\n--- %s ping statistics ---\n"
		   "%u packets transmitted, %u received, ",
		   g_env.opt.host,
		   g_env.stats.n_sent, g_env.stats.n_received
		);

	if (g_env.stats.n_errors)
		printf("+%d errors, ", g_env.stats.n_errors);

	printf("%.5g%% packet loss, time %ums\n",
		   100 - (double)g_env.stats.n_received / (double)g_env.stats.n_sent * 100.,
		   time_diff(&g_env.start_time, &now) / 1000
		);

	if (g_env.stats.n_received)
		printf("rtt min/avg/max/mdev = %.3f/%.3f/%.3f/%.3f ms\n",
		   g_env.stats.min_trip_time,
		   avg,
		   g_env.stats.max_trip_time,
		   ft_sqrtl(
			   g_env.stats.trip_time_sum_squared / g_env.stats.n_received
			   - (double)avg * (double)avg
			   )
		);

	if (!g_env.stats.n_received
		|| (g_env.opt.deadline && g_env.stats.n_received < g_env.opt.n_packets))
		exit(PING_FAILURE);
	exit(PING_SUCCESS);
}

static void		alarm_handler(int i)
{
	struct timeval	now;
	(void)i;

	if ((g_env.opt.flags & FLAG_C)
		&& g_env.stats.n_sent >= g_env.opt.n_packets)
		interupt_handler(42);

	gettimeofday(&now, NULL);
	if ((g_env.opt.flags & FLAG_W)
		&& USEC_TO_SEC(time_diff(&g_env.start_time, &now)) >= (t_dword)g_env.opt.deadline)
		interupt_handler(42);

	send_packet();
}

void			sig_init(t_dword usec_interval)
{
	struct itimerval t;

	if (!usec_interval)
		usec_interval = SEC_TO_USEC(1); // default to 1 sec

	signal(SIGALRM, alarm_handler);
	t.it_value.tv_sec = (t_dword)USEC_TO_SEC(usec_interval);
	t.it_value.tv_usec = usec_interval - SEC_TO_USEC(t.it_value.tv_sec);
	t.it_interval = t.it_value;
	if (setitimer(ITIMER_REAL, &t, NULL) == -1)
	{
		perror("error calling setitimer()"); /* DEBUG */
		exit(PING_ERROR);
	}
	alarm_handler(SIGALRM); // don't wait for the first packet
	signal(SIGINT, interupt_handler);
}
