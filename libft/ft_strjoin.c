/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:46:25 by ikhadem           #+#    #+#             */
/*   Updated: 2019/10/28 18:28:04 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	if (!(res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	ft_memcpy(res, s1, ft_strlen(s1));
	ft_memcpy(res + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (res);
}
