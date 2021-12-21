/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:36:19 by rbourdil          #+#    #+#             */
/*   Updated: 2021/12/21 10:58:27 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*leftover[1024] = {NULL};
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	int			size;

	while (ft_strchr(leftover[fd]) == NULL)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size <= 0 && leftover[fd] != NULL)
		{
			line = ft_strdup(leftover[fd]);
			free(leftover[fd]);
			leftover[fd] = NULL;
			return (line);
		}
		else if (size <= 0 && leftover[fd] == NULL)
			return (NULL);
		buf[size] = '\0';
		line = ft_strjoin(leftover[fd], buf);
		free(leftover[fd]);
		leftover[fd] = line;
	}
	line = extract_line(&leftover[fd]);
	return (line);
}
