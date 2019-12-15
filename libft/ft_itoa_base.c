/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:53:52 by ikhadem           #+#    #+#             */
/*   Updated: 2019/11/13 16:39:48 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base(int c, int base)
{
	char	*res;
	char	*tab_base;
	int		sign;

	if (!(res = (char *)malloc(sizeof(char) * 100)))
		return (NULL);
	sign = c < 0 ? -1 : 1;
	tab_base = "0123456789abcdef";
	*--res = '\0';
	*--res = tab_base[sign * (c % base)];
	c = c / base;
	while (c != 0)
	{
		*--res = tab_base[sign * (c % base)];
		c = c / base;
	}
	sign < 0 ? (*--res = '-') : 0;
	res = ft_strdup(res);
	return (res);
}
