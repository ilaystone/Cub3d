/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:04:37 by ikhadem           #+#    #+#             */
/*   Updated: 2019/10/17 08:10:07 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t slen;
	size_t dlen;

	slen = ft_strlen(src);
	dlen = SL_SIZE(size, ft_strlen(dest));
	if (dlen == size)
		return (size + slen);
	if (slen < size - dlen)
		ft_memcpy(dest + dlen, src, slen + 1);
	else
	{
		ft_memcpy(dest + dlen, src, size - 1);
		dest[size - 1] = '\0';
	}
	return (dlen + slen);
}
