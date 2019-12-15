/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 12:55:49 by ikhadem           #+#    #+#             */
/*   Updated: 2019/10/23 06:56:27 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tmp;

	if (!(tmp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		tmp->content = NULL;
		tmp->next = NULL;
	}
	else
	{
		tmp->content = content;
		tmp->next = NULL;
	}
	return (tmp);
}
