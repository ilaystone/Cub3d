/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:43:18 by ikhadem           #+#    #+#             */
/*   Updated: 2019/10/16 13:43:20 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char *s;

	if (!len || dest == src)
		return (dest);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (s < d)
		while (len--)
			*(d + len) = *(s + len);
	else
		while (len--)
			*d++ = *s++;
	return (dest);
}
