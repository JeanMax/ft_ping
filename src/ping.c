/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:43:47 by mc                #+#    #+#             */
/*   Updated: 2018/08/27 14:49:33 by mc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"


#ifdef ANNOYING_DEBUG
static void debugmsg(struct msghdr *msg)
{
	DEBUGF("-----------------------------------");
	DEBUGF("namelen: %d", msg->msg_namelen);
	DEBUGF("name:");
	write(2, msg->msg_name, msg->msg_namelen);
	write(2, "\n", 1);

	DEBUGF("iolen: %zu", msg->msg_iovlen);
//	if (msg->msg_iovlen > 0)
//	{
		DEBUGF("iobase:");
//		write(1, msg->msg_iov->iov_base, msg->msg_iov->iov_len);
		write(2, msg->msg_iov->iov_base, 4);
		write(2, "\n", 1);
//	}

	DEBUGF("controllen: %zu", msg->msg_controllen);
	DEBUGF("flags: %d", msg->msg_flags);
	DEBUGF("-----------------------------------");
}

static void debugsock(int sock, struct sockaddr_in *to)
{
	struct msghdr msg;
	struct iovec iov;

	ft_bzero((void *)&msg, sizeof(msg));
	ft_bzero((void *)&iov, sizeof(iov));

	if (fork())
	{
		if (recvmsg(sock, &msg, 0) < 0)
			perror("recvmsg() failed");
		DEBUGF("recv:"); //debug
		debugmsg(&msg); //debug
	}
	else
	{
//		sleep(1);
		msg.msg_name = to->sin_addr;
		msg.msg_namelen = to->sin_addrlen;
		msg.msg_iov = &iov;
		msg.msg_iovlen = 1;
		iov.iov_base = ft_strdup("toto");
//		ft_memcpy(iov.iov_base, "toto", 4);


		iov.iov_len = 5;
		DEBUGF("send:"); //debug
		debugmsg(&msg); //debug
		if (sendmsg(sock, &msg, 0) < 0)
 			perror("sendmsg() failed");
//		sendto(sock, &msg, sizeof(msg), 0, to, sizeof(to));
		exit(0);
	}
}
#endif //ANNOYING_DEBUG

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

int						ping(char *host, t_byte flags)
{
	struct sockaddr	whereto;
	struct sockaddr_in	from;
	struct sockaddr_in	*to;

	int sock;

	(void)flags;
	to = (struct sockaddr_in *) &whereto;
	ft_bzero((void *)&whereto, sizeof(struct sockaddr));

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

#ifdef ANNOYING_DEBUG
	debugsock(sock, to);
	DEBUGF("host: %s", host);
	DEBUGF("sock: %d", sock);
	if ((flags & FLAG_V))
		DEBUGF("FLAG V: %d", (int)flags);
#endif //ANNOYING_DEBUG

	return (EXIT_FAILURE);
}