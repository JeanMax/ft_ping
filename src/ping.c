/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:43:47 by mc                #+#    #+#             */
/*   Updated: 2018/08/27 18:06:37 by mc               ###   ########.fr       */
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

static int				socks_loop(struct addrinfo *rp)
{
	int sock;

	if (rp == NULL)
		return (-1);
	sock = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
	if (sock != -1)
	{
		ft_memcpy(&g_env.addr_info, rp, sizeof(struct addrinfo));
		return (sock);
	}
	return (socks_loop(rp->ai_next));
}

static int				get_sock(char *host)
{
	struct addrinfo hints;
	struct addrinfo *result;
	int	sock;

	ft_bzero((void *)&hints, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_RAW;
	hints.ai_flags = AI_CANONNAME;
	hints.ai_protocol = IPPROTO_ICMP;

	if (getaddrinfo(host, NULL, &hints, &result))
		error(ADDRINFO, NULL);

	sock = socks_loop(result);

	freeaddrinfo(result);
	return (sock);
}

static void				print_header(char *host)
{
	char	addr_buf[INET6_ADDRSTRLEN];
	void	*addr;

	if (g_env.addr_info.ai_family == AF_INET6)
		addr = &((struct sockaddr_in6*)(g_env.addr_info.ai_addr))->sin6_addr;
	else
		addr = &((struct sockaddr_in*)(g_env.addr_info.ai_addr))->sin_addr;

	if (!inet_ntop(g_env.addr_info.ai_family, \
				   addr, \
				   addr_buf, \
				   INET6_ADDRSTRLEN))
		error(INET_NTOP, NULL);
	printf("PING %s (%s) %d(%d) bytes of data.\n", host, addr_buf, 56, 84); //TODO
}

int						ping(char *host, t_byte flags)
{
	int sock;
	(void)flags;

	if ((sock = get_sock(host)) == -1)
		error(SOCKET, NULL);

	print_header(host);

#ifdef ANNOYING_DEBUG
	debugsock(sock, to);
	DEBUGF("host: %s", host);
	DEBUGF("sock: %d", sock);
	if ((flags & FLAG_V))
		DEBUGF("FLAG V: %d", (int)flags);
#endif //ANNOYING_DEBUG

	return (EXIT_FAILURE);
}
