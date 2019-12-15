/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:15:44 by ikhadem           #+#    #+#             */
/*   Updated: 2019/10/16 14:15:46 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t len)
{
	unsigned char *t1;
	unsigned char *t2;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	while (len--)
	{
		if (*t1 != *t2)
			return ((int)(*t1 - *t2));
		t1++;
		t2++;
	}
	return (0);
}
