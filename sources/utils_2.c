/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:34:21 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/04 00:31:09 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_putnbr(int n)
{
	unsigned int nbr;

	if (n < 0)
	{
		ft_putchar('-');
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
}

int		ft_strncmp(const char *s1, const char *s2, size_t len)
{
	unsigned char *t1;
	unsigned char *t2;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	while (len--)
	{
		if (*t1 != *t2 || *t1 == '\0')
			return ((int)(*t1 - *t2));
		t1++;
		t2++;
	}
	return (0);
}
