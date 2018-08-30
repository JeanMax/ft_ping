/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 04:34:21 by mcanal            #+#    #+#             */
/*   Updated: 2018/08/30 15:32:22 by mc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the place to handle signals of course!
*/

#include "ft_ping.h"

static void		interupt_handler(int i)
{
	(void)i;
	//TODO: print stats
	/* tsum += triptime; */
	/* tsum2 += (long long)triptime * (long long)triptime; */
	/* tsum /= nreceived + nrepeats; */
	/* tsum2 /= nreceived + nrepeats; */
	/* tmdev = llsqrt(tsum2 - tsum * tsum); */

	/* mdev = SQRT(SUM(RTT*RTT) / N – (SUM(RTT)/N)^2) */
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
