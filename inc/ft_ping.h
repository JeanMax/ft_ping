/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:23:15 by mcanal            #+#    #+#             */
/*   Updated: 2018/08/28 16:44:10 by mc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <sys/time.h>
# include <arpa/inet.h>
# include <netinet/ip.h>
# include <netinet/ip_icmp.h>
# include <netdb.h>


/*
** bool handling
*/
# ifndef TRUE
#  define TRUE			1
#  define FALSE			0
# endif //TRUE

typedef int				t_bool;

/*
** some types for memory handling
*/
typedef unsigned char	t_byte;
typedef unsigned short	t_word;
typedef unsigned int	t_dword;

/*
** command line flags
*/
# define NO_FLAG	0
# define FLAG_V		1
/*
# define FLAG_H		2
# define FLAG_Q		4
# define FLAG_T		8
*/

/*
** error handling
*/
enum	e_error
{
	USAGE,
	ROOT,
	MALLOC,
	INET_NTOP,
	INET_PTON,
	ADDRINFO,
	SOCKET
};

/*
** some colors for pretty printing
*/
# define CLR_BLACK "\033[30;01m"
# define CLR_RED "\033[31;01m"
# define CLR_GREEN "\033[32;01m"
# define CLR_YELLOW "\033[33;01m"
# define CLR_BLUE "\033[34;01m"
# define CLR_MAGENTA "\033[35;01m"
# define CLR_CYAN "\033[36;01m"
# define CLR_WHITE "\033[37;01m"
# define CLR_RESET "\033[0m"

/*
** optional debug statements
*/
/* # define ANNOYING_DEBUG */
# ifdef ANNOYING_DEBUG
#  include <stdio.h>
#  define DEBUG_HEADER CLR_MAGENTA "[DEBUG] " CLR_RESET
#  define DEBUGF(str, ...) fprintf(stderr, DEBUG_HEADER "<" str ">" CLR_RESET "\n", ##__VA_ARGS__)
# else
#  define DEBUGF(str, ...) do {} while (0)
# endif //ANNOYING_DEBUG


/*
** packet struct
*/
#define PACKET_SIZE  32
typedef struct s_packet	t_packet;
struct		s_packet
{
	struct icmphdr		header;
	struct timeval		timestamp;
	t_byte				data[PACKET_SIZE];
};

/*
** env struct
*/
typedef struct s_env	t_env;
struct		s_env
{
	struct addrinfo		addr_info;
};

/*
** GLOBAD
*/
extern t_env			g_env;

/*
**	-error.c
*/
void					error(enum e_error e, char *msg);

/*
**	-signal.c
*/
void					sig_init(void);

/*
**	-util.c
*/
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);

/*
**	-ping.c
*/
int						ping(char *host, t_byte flags);

#endif //FT_PING_H
