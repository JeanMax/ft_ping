/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 15:07:35 by mcanal            #+#    #+#             */
/*   Updated: 2015/11/23 14:32:19 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"


static t_bool			parse_flags(char *s, t_char *flags)
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

static char				*parse_av(char **av, t_char *flags)
{
	if (!(*av) || **av != '-')
		return (*av && *(av + 1) ? NULL : *av);

	if (!(parse_flags(*av + 1, flags)))
		return (NULL);

	return (parse_av(av + 1, flags));
}


static int				socks_loop(int sock, struct addrinfo *rp)
{
	return (sock != -1 || rp == NULL ? sock : \
			socks_loop(socket(rp->ai_family, \
							  rp->ai_socktype, \
							  rp->ai_protocol), rp->ai_next));
}

static int				get_sock(char *host)
{
	struct addrinfo hints;
	struct addrinfo *result;
	int	sock;

	ft_bzero((void *)&hints, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;    /* Allow IPv4 or IPv6 */
	hints.ai_socktype = SOCK_DGRAM; /* Datagram socket */
	hints.ai_flags = 0;
	hints.ai_protocol = 0;          /* Any protocol */

	if (getaddrinfo(host, "http", &hints, &result))
		error(ADDRINFO, NULL);

	sock = socks_loop(-1, result);

	freeaddrinfo(result);
	return (sock);
}

static void debugsock(int sock, struct sockaddr *to)
{
	struct msghdr msg;
	struct iovec iov;

//	ft_bzero((void *)&msg, sizeof(struct msghdr));
	ft_bzero((void *)&iov, sizeof(struct iovec));
	msg.msg_iov = &iov;
	msg.msg_iovlen = 1;

	if (fork())
	{
		recvmsg(sock, &msg, 0);
		ft_debugstr("msg", msg.msg_iov->iov_base);
	}
	else
	{
		sleep(1);
		iov.iov_base = ft_strdup("toto");
		iov.iov_len = 5;
		sendmsg(sock, &msg, 0);
//		sendto(sock, &msg, sizeof(msg), 0, to, sizeof(to));
		exit(0);
	}
		
	
}

int						main(int ac, char **av)
{
	t_char	flags;
	char	*host;
	struct sockaddr	whereto;
	struct sockaddr_in	from;
	struct sockaddr_in	*to;

	int sock;

	to = (struct sockaddr_in *) &whereto;
	ft_bzero((void *)&whereto, sizeof(struct sockaddr));

	flags = NO_FLAG;
	host = NULL;
	if (ac < 2 || ac > 4 || !(host = parse_av(av + 1, &flags)))
		error(USAGE, *av);


	to->sin_family = AF_INET;

	if ((inet_pton(to->sin_family, host, &(to->sin_addr))) <= 0)
	{
		to->sin_family = AF_INET6;
		if ((inet_pton(to->sin_family, host, &(to->sin_addr))) <= 0)
			error(INET_PTON, NULL);
	}


	if ((sock = get_sock(host)) == -1)
		error(SOCKET, NULL);


/*	
	char	str[INET6_ADDRSTRLEN];
	if (inet_ntop(to->sin_family, &(to->in_addr), str, INET6_ADDRSTRLEN) == NULL)
		error(INET_NTOP, NULL);
	ft_debugstr("str", str); //debug
*/

	
	 //debug
	debugsock(sock, (struct sockaddr *) to);
	ft_debugstr("host", host);
	ft_debugnbr("sock", sock);
	if ((flags & FLAG_V))
		ft_debugnbr("FLAG V", (int)flags);
	//debug
	
	return (EXIT_FAILURE);
}
