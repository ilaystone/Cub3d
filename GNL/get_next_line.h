/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:36:57 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/01 18:18:44 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <libc.h>
# include <stdlib.h>
# include <stdio.h>

# define MAX_FD 10240

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

int		has_char(char *str, int c);
int		get_next_line(int fd, char **line);
int		set_line(char **reads, char **line, int fd);
char	*ft_substr(const char *str, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t len);

#endif
