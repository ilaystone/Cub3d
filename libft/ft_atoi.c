/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 08:24:51 by ikhadem           #+#    #+#             */
/*   Updated: 2019/11/12 18:52:38 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
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
