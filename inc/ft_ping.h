/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:23:15 by mcanal            #+#    #+#             */
/*   Updated: 2015/11/19 17:18:47 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H

/*
** DEFINE
*/
# define FT_PING_H

# define NO_FLAG	0
# define FLAG_V		1
# define FLAG_H		2
/*
# define FLAG_Q		4
# define FLAG_T		8
*/

/*
** INCLUDE
*/
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <arpa/inet.h>

/*
** ENUM
*/
enum	e_error
{
	USAGE,
	MALLOC,
	BUS,
	SEG,
	FPE,
	INET_NTOP,
	INET_PTON
};


/*
** STRUCT && TYPEDEF
typedef struct s_env	t_env;
struct		s_env
{
	char	 zboub;
};
*/

/*
** GLOBAL
extern t_env			*g_env;
*/

/*
** PROTOTYPES
**	-error.c
*/
void					error(char e, char *msg);

/*
**	-signal.c
*/
void					sig_init(void);

#endif
