/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 01:21:01 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/13 17:07:48 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *str)
{
	char		*res;

	if (!(res = (char *)malloc(ft_strlen(str) + 1)))
		return (NULL);
	return ((char *)ft_memcpy(res, str, ft_strlen(str) + 1));
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char		*res;

	if (!(res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	ft_memcpy(res, s1, ft_strlen(s1));
	ft_memcpy(res + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (res);
}

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	if (!str)
		return (NULL);
	if (!(res = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	i = 0;
	if (!(start > ft_strlen(str)))
	{
		while (i < len && str[i + start] != '\0')
		{
			res[i] = str[i + start];
			i++;
		}
	}
	res[i] = '\0';
	return (res);
}

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

size_t	ft_strlen(const char *s)
{
	size_t		size;

	if (!s)
		return (0);
	size = 0;
	while (*s++)
		size++;
	return (size);
}
