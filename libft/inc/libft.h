/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:13:23 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/15 20:04:03 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# define BUFF_SIZE	127
# define TRUE		1
# define FALSE		0
# define INT_MAX    2147483647
# define INT_MIN    (-INT_MAX - 1)

# include <string.h>
# include "edit.h"

typedef unsigned char	t_char;
typedef int				t_bool;

/*
** io
*/
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	*fail(char const *s);
void	*failn(char const *s);
void	ft_putdbl(double nbr);
void	ft_putdbl_fd(double nbr, int fd);
void	ft_putnbr(int nbr);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr(char const *s);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putdbl_clr(double nbr, char *clr);
void	ft_putnbr_clr(int nbr, char *clr);
void	ft_putstr_clr(char *s, char *clr);
void	ft_putendl_clr(char *s, char *clr);
void	ft_putchar_clr(char c, char *clr);
void	ft_debugstr(char *name, char *str);
void	ft_debugnbr(char *name, int nbr);
void	ft_debugdbl(char *name, double nbr);
int		get_all(int const fd, char **a);
int		get_next_line(int const fd, char **line);
int		get_line(int const fd, char **a);

/*
** is
*/
int		ft_isalnum(int i);
int		ft_isalpha(int i);
int		ft_isascii(int i);
int		ft_isblank(int c);
int		ft_iscntrl(int c);
int		ft_isdigit(int i);
int		ft_isgraph(int c);
int		ft_islower(int c);
int		ft_isprint(int i);
int		ft_ispunct(int c);
int		ft_isspace(int c);
int		ft_istoobig(char *s);
int		ft_isupper(int c);
int		ft_isxdigit(int c);

/*
** lst1
*/
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstaddlast(t_list **alst, t_list *new);
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdellink(t_list **alst, t_list *lst);
void	ft_lstinser(t_list **alst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void	ft_lstrplc(t_list **alst, t_list *old, t_list *new);
int		ft_lstisempty(t_list **alst);
int		ft_lstislast(t_list **alst);
int		ft_lstisn(t_list **alst, t_list *lst);
int		ft_lstlen(t_list **alst);
t_list	*ft_lstlast(t_list **alst);
t_list	*ft_lstat(t_list **alst, size_t n);

/*
** lst2
*/
void	ft_ladd(t_lst **alst, t_lst *new);
void	ft_laddlast(t_lst **alst, t_lst *new);
void	ft_ldellink(t_lst *lst);
void	ft_linser(t_lst **alst, t_lst *new);
void	ft_liter(t_lst *lst, void (*f)(t_lst *elem));
void	ft_lrplc(t_lst *old, t_lst *new);
void	ft_lswap(t_lst *lst1, t_lst *lst2);
int		ft_lisempty(t_lst **alst);
int		ft_lisfirst(t_lst **alst);
int		ft_lislast(t_lst **alst);
int		ft_lisn(t_lst **alst, t_lst *lst);
int		ft_llen(t_lst **alst);
t_lst	*ft_lat(t_lst **alst, size_t n);
t_lst	*ft_lfirst(t_lst **alst);
t_lst	*ft_llast(t_lst **alst);
void	ft_lclean(t_lst **alst);

/*
** mem
*/
void	ft_bzero(void *s, size_t n);
char	**ft_cpystab(char **tab, char *val);
void	ft_freestab(char **tab);
void	ft_memdel(void **ap);
void	*ft_memalloc(size_t size);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_realloc(void *old, size_t old_size, size_t new_size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** str
*/
void	ft_strclr(char *s);
void	ft_strdel(char **as);
void	ft_striter(char *s, void (*f)(char*));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
int		ft_atoi(char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strindex(const char *s, int c);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strrindex(const char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strncat(char *dest, const char *src, size_t n);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strndup(char *src, size_t n);
char	*ft_strnew(size_t size);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strstr(const char *str, const char *to_find);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);

#endif
