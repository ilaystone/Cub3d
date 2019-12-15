/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:25:00 by ikhadem           #+#    #+#             */
/*   Updated: 2019/10/16 13:26:49 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	if (!len || dest == src)
		return (dest);
	d = (char *)dest;
	s = (const char *)src;
	while (len--)
		*d++ = *s++;
	return (dest);
}
