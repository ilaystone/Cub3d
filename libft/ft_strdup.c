/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 09:08:28 by ikhadem           #+#    #+#             */
/*   Updated: 2019/10/17 09:29:52 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*res;

	if (!(res = (char *)malloc(ft_strlen(str) + 1)))
		return (NULL);
	return ((char *)ft_memcpy(res, str, ft_strlen(str) + 1));
}
