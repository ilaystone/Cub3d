/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upperstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:53:40 by ikhadem           #+#    #+#             */
/*   Updated: 2019/11/06 16:56:00 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_upperstr(char *str)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc(ft_strlen(str));
	while (str[i])
	{
		res[i] = ft_toupper(str[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
