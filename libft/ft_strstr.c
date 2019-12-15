/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:54:18 by ikhadem           #+#    #+#             */
/*   Updated: 2019/10/16 21:08:32 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (ft_strncmp(needle, "", 1) == 0)
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
				return ((char *)(haystack));
		}
		haystack++;
	}
	return (NULL);
}
