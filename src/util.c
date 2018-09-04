/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:12:13 by mc                #+#    #+#             */
/*   Updated: 2018/09/04 14:59:00 by mc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** general purpose functions
*/

#include "ft_ping.h"


/*
** The  memcpy()  function  copies  n bytes from memory area src to memory
** area dest.  The memory areas must not overlap.  Use memmove(3)  if  the
** memory areas do overlap.
*/
void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dswap;
	const char	*sswap;

	dswap = dest;
	sswap = src;
	if (dest != src)
		while (n--)
			*dswap++ = *sswap++;
	return (dest);
}

/*
** The  memcmp()  function compares the first n bytes (each interpreted as
** unsigned char) of the memory areas s1 and s2.
*/
int				ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *swap1;
	const unsigned char *swap2;

	if (s1 != s2 && n)
	{
		swap1 = (const unsigned char *)s1;
		swap2 = (const unsigned char *)s2;
		while (n--)
		{
			if (*swap1 != *swap2)
				return (*swap1 - *swap2);
			swap1++;
			swap2++;
		}
	}
	return (0);
}


/*
** checks for white-space  characters.   In  the  "C"  and  "POSIX"
** locales,  these  are:  space,  form-feed ('\f'), newline ('\n'),
** carriage return ('\r'), horizontal tab ('\t'), and vertical  tab
** ('\v').
*/
static int		ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
			|| c == ' ')
		return (TRUE);
	return (FALSE);
}

/*
** checks for a digit (0 through 9).
*/
static int		ft_isdigit(int i)
{
	if (i >= '0' && i <= '9')
		return (TRUE);
	return (FALSE);
}

/*
** The atoi() function converts the initial portion of the string  pointed
** to by nptr to int.
** If the string cannot be converted into a number, atoi returns 0.
** If the string represents a numeric value greater/lower than INT_MAX/MIN,
** INT_MAX/MIN will be returned
*/
int				ft_atoi(char *str)
{
	t_bool	negative;
	long	ret;

	while (ft_isspace(*str))
		str++;
	negative = *str == '-' ? TRUE : FALSE;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str == '0')
		str++;
	ret = 0;
	while (*str && ft_isdigit(*str) && ret < INT_MAX)
		ret = ret * 10 + *(str++) - '0';
	if (negative)
		return (ret > INT_MAX ? INT_MIN : (int)-ret);
	else
		return (ret > INT_MAX ? INT_MAX : (int)ret);
}


/*
** return the difference in microseconds from 'since' to 'now'
*/
t_dword			time_diff(struct timeval *since, struct timeval *now)
{
	if (now->tv_usec > since->tv_usec)
		return (now->tv_sec - since->tv_sec) * (t_dword)1e6
			+ (now->tv_usec - since->tv_usec);

	return (now->tv_sec - since->tv_sec - 1) * (t_dword)1e6
		+ (now->tv_usec - since->tv_usec + (t_dword)1e6);
}
