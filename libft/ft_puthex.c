/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:16:25 by ikhadem           #+#    #+#             */
/*   Updated: 2019/11/04 13:24:07 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(long int n, int type)
{
	unsigned long int	nbr;
	int					sign;
	char				c;

	sign = n < 0 ? -1 : 1;
	nbr = n * sign;
	if (n < 0)
		ft_putchar('-');
	if (nbr >= 16)
		ft_puthex(nbr / 16, type);
	if (type == L_HEXA)
		c = nbr % 16 >= 10 ? nbr % 16 + 87 : nbr % 16 + 48;
	else
		c = nbr % 16 >= 10 ? nbr % 16 + 55 : nbr % 16 + 48;
	ft_putchar(c);
}
