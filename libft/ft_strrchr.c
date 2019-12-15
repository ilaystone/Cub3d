/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:53:36 by ikhadem           #+#    #+#             */
/*   Updated: 2019/10/16 18:54:30 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t slen;

	slen = ft_strlen(str);
	if ((char)c == '\0')
		return ((char *)(str + slen));
	while (slen--)
		if (str[slen] == (char)c)
			return ((char *)(str + slen));
	return (NULL);
}
