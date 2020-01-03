/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 16:43:08 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/02 21:42:16 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"

void		ft_putchar(char c);
void		ft_puterror(char *msg);
int			ft_isspace(char c);
int			ft_atoi(const char *str);
int			ft_isdigit(char c);
void		ft_putnbr(int n);
void		*ft_memcpy(void *dest, const void *src, size_t len);
char		*ft_strjoin(const char *s1, const char *s2);

#endif
