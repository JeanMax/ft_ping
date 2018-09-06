/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:23:15 by mcanal            #+#    #+#             */
/*   Updated: 2018/09/06 15:10:26 by mcanal           ###   ########.fr       */
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

/* If ping does not receive any reply packets at all it will exit with code 1.  */
/* If a packet count and deadline are both specified, and fewer than */
/* count packets are received by the time the deadline has arrived, it will */
/* also exit with code 1. On other error it exits with code 2. Otherwise */
/* it exits with code 0. This makes it possible to use the exit code to see */
/* if a host is alive or not. */
# define PING_SUCCESS	0
# define PING_FAILURE	1
# define PING_ERROR		2

/*
** bool handling
*/
# ifndef TRUE
#  define TRUE			1
#  define FALSE			0
# endif //TRUE

typedef int				t_bool;


/*
** limits
*/
# ifndef INT_MAX
#  define SHRT_MAX		32767
#  define SHRT_MIN		(-SHRT_MAX - 1)
#  define USHRT_MAX		(2 * SHRT_MAX + 1)
#  define INT_MAX		2147483647
#  define INT_MIN		(-INT_MAX - 1)
#  define UINT_MAX		(2 * INT_MAX + 1)
#  define LONG_MAX		9223372036854775807
#  define LONG_MIN		(-LONG_MAX - 1)
#  define ULONG_MAX		(2 * LONG_MAX + 1)
# endif

/*
** some types for memory handling
*/
typedef unsigned char	t_byte;
typedef unsigned short	t_word;
typedef unsigned int	t_dword;

/*
** this is always useful
*/
# ifndef MIN
#  define MIN(a, b) ((a) < (b) ? (a) : (b))
# endif

# ifndef MAX
#  define MAX(a, b) ((a) > (b) ? (a) : (b))
# endif

# ifndef ABS
#  define ABS(x) ((x) < 0 ? -(x) : (x))
# endif

# define TOLERANCE		1e-4  // precision needed for square root computing

/*
** time helper
*/
# define SEC_TO_USEC(x) (t_dword)((x) * 1e6)
# define USEC_TO_SEC(x) ((double)(x) / 1e6)

/*
** error handling
*/
enum	e_error
{
	USAGE,
	ROOT,
	INET_NTOP,
	ADDRINFO,
	SOCKET,
	IPV6
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
# define ANNOYING_DEBUG
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
#define PACKET_DATA_SIZE  40
typedef struct s_packet	t_packet;
struct		s_packet
{
	struct icmphdr		header;
	struct timeval		timestamp;
	t_byte				data[PACKET_DATA_SIZE];
};

# define IOV_BUF_SIZE (sizeof(t_packet))

/*
** packet stats struct
*/
typedef struct s_packet_stats	t_packet_stats;
struct		s_packet_stats
{
	t_word				n_sent;
	t_word				n_received;
	long double			trip_time_sum;
	long double			trip_time_sum_squared;
	double				max_trip_time;
	double				min_trip_time;
	t_word				n_errors;
};


/*
** command line flags
*/
# define NO_FLAG	0
# define FLAG_V		(1 << 1)
# define FLAG_Q		(1 << 2)
# define FLAG_C		(1 << 3)
# define FLAG_T		(1 << 4)
# define FLAG_I		(1 << 5)
# define FLAG_W		(1 << 6)
# define FLAG_F		(1 << 7)
# define FLAG_D		(1 << 8)

# define NEXT_ARG	2

/*
** command line options struct
*/
typedef struct s_options	t_options;
struct		s_options
{
	char				*host;
	t_dword				flags;
	int					ttl;
	int					n_packets;
	int					interval; //ms
	int					deadline; //s
};


/*
** env struct
*/
typedef struct s_env	t_env;
struct		s_env
{
	struct addrinfo		addr_info;
	char				addr_str[INET6_ADDRSTRLEN];
	t_options			opt;
	int					sock;
	t_packet_stats		stats;
	struct timeval		start_time;
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
void					sig_init(t_dword usec_interval);
void					interupt_handler(int i);


/*
**	-util.c
*/
void					*ft_memcpy(void *dest, const void *src, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
int						ft_atoi(char *str);
double					ft_sqrtl(double x);
t_dword					time_diff(struct timeval *since, struct timeval *now);

/*
**	-ping.c
*/
int						ping(void);

/*
** -socket.c
*/
int						get_sock(void);

/*
** -packet.c
*/
int						send_packet(void);
int						recv_packet(void);

#endif //FT_PING_H
