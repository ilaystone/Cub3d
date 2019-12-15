/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 08:41:16 by ikhadem           #+#    #+#             */
/*   Updated: 2019/10/28 18:28:57 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_replacechr(const char *str, int o, int s)
{
	size_t	i;
	char	*res;

	res = ft_strdup(str);
	i = 0;
	while (res[i] != '\0')
	{
		if (res[i] == o)
			res[i] = s;
		i++;
	}
	return (res);
}

static int		ft_countwords(const char *str, int c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != c && str[i - 1] == c) || (str[i] != c && i == 0))
			count++;
		i++;
	}
	return (count);
}

char			**ft_split(const char *str, int c)
{
	char	*temp;
	char	**res;
	size_t	pos;
	size_t	len;

	if (!str)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) * (ft_countwords(str, c) + 1))))
		return (NULL);
	pos = 0;
	len = 0;
	temp = ft_strdup(str);
	temp = ft_replacechr(temp, c, '\0');
	while (len < ft_strlen(str))
	{
		while (temp[len] == '\0')
			len++;
		res[pos] = ft_strdup(temp + len);
		pos++;
		while (temp[len] != '\0')
			len++;
	}
	res[ft_countwords(str, c)] = NULL;
	free(temp);
	return (res);
}
