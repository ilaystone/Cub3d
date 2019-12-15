/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 06:41:16 by ikhadem           #+#    #+#             */
/*   Updated: 2019/10/28 18:28:34 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isinset(const char *set, int c)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char			*ft_strtrim(const char *str, const char *set)
{
	size_t	start;
	size_t	end;

	if (!str || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(str);
	while (ft_isinset(set, str[start]) && str[start] != '\0')
		start++;
	while (ft_isinset(set, str[end - 1]) && end > start)
		end--;
	return (ft_substr(str, start, end - start));
}
