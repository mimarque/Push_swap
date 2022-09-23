/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:24:15 by mimarque          #+#    #+#             */
/*   Updated: 2022/07/20 23:10:02 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <fcntl.h>

/* printf defines */
# define MY_TYPES "diuoxXfFeEgGaAcspn%"
# define MAXBUF 348
# define BUF 34
# define U_LONG unsigned long
# define MY_DIU "diouXx"
# define MY_DIUP "pdiouXx"
# define MY_UNSIGNED "uoxX"
# define MY_NUMS "123456789"
# define NO_SIGN_TYPE "cspuoxX"

/* Get_Next_Line defines */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef NUM_OF_FD
#  define NUM_OF_FD 256
# endif

/* linked list struct */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* printf struct */
/*
	A format specifier follows this prototype:
	%[param][flags][width][.precision][length]specifier
*/
typedef struct s_args
{
	char	*type;
	char	*cp;
	char	*pref;
	char	c;
	char	hash;
	char	dash;
	char	star;
	char	zero;
	char	dot;
	char	sign;
	char	base;
	int		width;
	int		precision;
	int		dprec;
	int		caps;
	int		size;
	int		realsz;
	int		prsize;
	U_LONG	ulval;
}	t_args;

/* Part I & II*/
int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *destination, const char *source, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strpbrk(const char *s, char *accept);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_substrpbrk(char *s, size_t len, char *accept);
int		ft_tolower(int c);
int		ft_toupper(int c);

/* bonus */
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
/* added to bonus */
t_list	*ft_lstpenultimate(t_list **lst);

/* printf */
void	ft_print(char *s, int len);
void	pad(int n, char with);
char	*print_base(char *cp, U_LONG value, unsigned int base, t_args *a);
int		get_value(char **format);
void	get_star(t_args *a, va_list args);
void	get_precision(t_args *a, char **format, va_list *args);
void	get_flags(char **fmt, t_args *a, va_list *args);
void	get_type_values(t_args *a, va_list *args);
void	adjustments(t_args *a);
void	s_setup(t_args *a);
void	csp_setup(t_args *a);
void	dioux_setup(t_args *a);
int		print_formating(t_args *a);
int		function_colection(char **fmt, t_args *a, va_list *args, char *buf);
int		ft_printf(const char *format, ...);

/* GNL */
//char	*ft_strchr(const char *s, int c);
char	*ft_strldup(char *s1, int start, int end);
char	*ft_strjoinfree(char *s1, char *s2);
//size_t	ft_strlen(const char *s);
char	*cycle(char **backup, int fd, char *buf);
char	*returner(char **backup, int fd);
char	*get_next_line(int fd);
#endif