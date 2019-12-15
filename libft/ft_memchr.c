/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:04:25 by ikhadem           #+#    #+#             */
/*   Updated: 2019/10/16 14:04:27 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t len)
{
	unsigned char *s;

	s = (unsigned char *)src;
	while (len--)
	{
		if (*s++ == (unsigned char)c)
			return (--s);
	}
	return (NULL);
}
