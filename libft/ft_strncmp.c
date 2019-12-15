/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:01:48 by ikhadem           #+#    #+#             */
/*   Updated: 2019/10/17 08:24:30 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
