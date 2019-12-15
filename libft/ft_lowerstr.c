/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowerstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:56:13 by ikhadem           #+#    #+#             */
/*   Updated: 2019/11/06 16:57:49 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lowerstr(char *str)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc(ft_strlen(str));
	while (str[i])
	{
		res[i] = ft_tolower(str[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
