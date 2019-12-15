/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:14:21 by ikhadem           #+#    #+#             */
/*   Updated: 2019/10/28 18:20:42 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
