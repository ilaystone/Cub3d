/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 09:30:55 by ikhadem           #+#    #+#             */
/*   Updated: 2019/11/08 13:32:51 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*res;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (!(res = (unsigned char *)malloc(size * count)))
		return (NULL);
	ft_bzero(res, count * size);
	return ((void *)res);
}
