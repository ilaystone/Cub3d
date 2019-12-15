/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 09:01:36 by ikhadem           #+#    #+#             */
/*   Updated: 2019/11/13 10:00:47 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define SL_SIZE(A, B) (A < B ? A : B)
# define ABS(A) (A < 0 ? -A : A)
# define U_HEXA 0
# define L_HEXA 1

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *dest, int c, size_t len);
void				ft_bzero(void *dest, size_t len);
void				*ft_memcpy(void *dest, const void *src, size_t len);
void				*ft_memccpy(void *dest, const void *src, int c, size_t len);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memchr(const void *src, int c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t len);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strncpy(char *dest, const char *src, size_t len);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strnstr(const char *h, const char *n, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isblank(int c);
int					ft_isspace(int c);
char				*ft_strdup(const char *str);
void				*ft_calloc(size_t count, size_t size);
char				*ft_substr(const char *str, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrimsp(const char *s);
char				*ft_strtrim(const char *str, const char *set);
char				**ft_split(const char *str, int c);
char				*ft_itoa(int c);
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *str, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putendl(char *str);
void				ft_putnbr(int n);
void				ft_puthex(long int n, int type);
void				ft_putptr(void *p);
char				*ft_itoa_base(int c, int base);
char				*ft_upperstr(char *str);
char				*ft_lowerstr(char *str);
char				*ft_newstr(size_t n);
int					ft_pow(int b, int p);
size_t				ft_wcharlen(unsigned c);
size_t				ft_wstrlen(char *str);
void				ft_swap(char *a, char *b);

/*
**		BONUS
*/

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
								void (*del)(void *));

#endif
