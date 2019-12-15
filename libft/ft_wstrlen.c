/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:11:25 by ikhadem           #+#    #+#             */
/*   Updated: 2019/11/12 20:35:04 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wstrlen(char *str)
{
	size_t		len;

	len = 0;
	while (*str != L'\0')
	{
		len += ft_wcharlen(*str);
		str++;
	}
	return (len);
}
