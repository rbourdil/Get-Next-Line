/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:36:19 by rbourdil          #+#    #+#             */
/*   Updated: 2021/12/20 16:55:21 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*leftover = NULL;
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	int			size;

	while (ft_strchr(leftover) == NULL)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size <= 0 && leftover != NULL)
		{
			line = ft_strdup(leftover);
			free(leftover);
			leftover = NULL;
			return (line);
		}
		else if (size <= 0 && leftover == NULL)
			return (NULL);
		buf[size] = '\0';
		line = ft_strjoin(leftover, buf);
		free(leftover);
		leftover = line;
	}
	line = extract_line(&leftover);
	return (line);
}
