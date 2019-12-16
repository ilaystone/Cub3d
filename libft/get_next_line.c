/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 01:10:36 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/15 23:25:53 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		has_char(char *str, int c)
{
	while (*str)
	{
		if (*str++ == c)
			return (1);
	}
	return (0);
}

/*
**	this function gets new line set it to postiing FD;
**	so it can rememcer last the pos of the cursor
**	and call multiple files read
**	TODO : make it analyse binary files
*/

int		get_next_line(int fd, char **line)
{
	static char		*reads[MAX_FD];
	char			str[BUFFER_SIZE + 1];
	char			*tmp;
	int				c;

	while ((c = read(fd, str, BUFFER_SIZE)) > 0)
	{
		str[c] = '\0';
		tmp = reads[fd];
		reads[fd] = ft_strjoin(tmp, str);
		free(tmp);
		if (has_char(str, '\n'))
			break ;
	}
	if (c < 0 || line == NULL)
		return (-1);
	else if (c == 0 && reads[fd] == NULL && (*line = ft_strdup("\0")))
		return (0);
	return (set_line(reads, line, fd));
}

/*
**	gets char by char from reads until '\n' and remove them
**	from reads leaving only the chars exlpicitly after '\n'
*/

int		set_line(char **reads, char **line, int fd)
{
	int		len;
	char	*tmp;

	len = 0;
	while (reads[fd][len] != '\n' && reads[fd][len] != '\0')
		len++;
	if (reads[fd][len] == '\n')
	{
		*line = ft_substr(reads[fd], 0, len);
		if (reads[fd] != NULL)
		{
			tmp = reads[fd];
			reads[fd] = ft_strdup(tmp + len + 1);
			free(tmp);
		}
	}
	else if (reads[fd][len] == '\0')
	{
		*line = ft_strdup(reads[fd]);
		free(reads[fd]);
		reads[fd] = NULL;
	}
	return (1);
}
