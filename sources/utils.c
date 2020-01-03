/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 16:37:15 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/01 18:44:07 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_putchar(char c)
{
	write(1 , &c, 1);
}

void		ft_puterror(char *msg)
{
	if (!msg)
		return ;
	while (*msg)
	{
		ft_putchar(*msg);
		msg++;
	}
}

int			ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

int			ft_isdigit(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int				sign;
	long			res;

	sign = 1;
	res = 0;
	while (ft_isspace(*str) && *str)
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str) && *str)
	{
		res = res * 10 + (unsigned int)(*str - '0');
		str++;
	}
	return (res * sign);
}