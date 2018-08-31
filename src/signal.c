/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 04:34:21 by mcanal            #+#    #+#             */
/*   Updated: 2018/08/31 00:01:01 by mc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the place to handle signals of course!
*/

#include "ft_ping.h"

static void		interupt_handler(int i)
{
	struct timeval	now;
	double			avg = (double)g_env.stats.trip_time_sum
		/ (double)g_env.stats.n_received;

	(void)i;
	gettimeofday(&now, NULL);
	printf("\n--- %s ping statistics ---\n"
		   "%u packets transmitted, %u received, %.3g%% packet loss, time %ums\n"
		   "rtt min/avg/max/mdev = %.3f/%.3f/%.3f/%.3Lf ms\n",
		   g_env.host,
		   g_env.stats.n_sent, g_env.stats.n_received,
		   100 - (double)(g_env.stats.n_received / g_env.stats.n_sent) * 100.,
		   (t_dword)time_diff(&g_env.start_time, &now),
		   g_env.stats.min_trip_time,
		   avg,
		   g_env.stats.max_trip_time,
		   sqrtl(
			   g_env.stats.trip_time_sum_squared / g_env.stats.n_received
			   - (long double)avg * (long double)avg
			   )
		);

	exit(EXIT_SUCCESS);
}

static void		alarm_handler(int i)
{
	(void)i;
	send_packet();
}

void			sig_init(t_dword usec_interval)
{
	struct itimerval t;

	signal(SIGINT, interupt_handler);
	signal(SIGALRM, alarm_handler);

	t.it_value.tv_sec = (t_dword)USEC_TO_SEC(usec_interval);
	t.it_value.tv_usec = usec_interval - SEC_TO_USEC(t.it_value.tv_sec);
	t.it_interval = t.it_value;
	if (setitimer(ITIMER_REAL, &t, NULL) == -1)
	{
		perror("error calling setitimer()"); /* DEBUG */
		exit(EXIT_FAILURE);
	}
	alarm_handler(SIGALRM); // don't wait for the first packet
}
