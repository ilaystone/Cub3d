/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:30:23 by ikhadem           #+#    #+#             */
/*   Updated: 2019/10/22 08:33:41 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	char	*temp;
	int		pos;

	if (ft_strncmp(n, "", 1) == 0)
		return ((char *)h);
	if (!(temp = (char *)malloc((len + 1) * sizeof(*h))))
		return (NULL);
	pos = 0;
	ft_strlcpy(temp, h, len + 1);
	while (temp[pos] != '\0')
	{
		if (temp[pos] == *n)
			if (ft_strncmp(temp + pos, n, ft_strlen(n)) == 0)
			{
				free(temp);
				return ((char *)(h + pos));
			}
		pos++;
	}
	free(temp);
	return (NULL);
}
