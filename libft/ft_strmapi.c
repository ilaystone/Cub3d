/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:39:19 by ikhadem           #+#    #+#             */
/*   Updated: 2019/10/28 18:29:33 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	if (!(res = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (*s)
	{
		res[i] = f(i, *s++);
		i++;
	}
	res[i] = '\0';
	return (res);
}
