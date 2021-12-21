/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:43:29 by rbourdil          #+#    #+#             */
/*   Updated: 2021/12/20 16:41:17 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		size1;
	int		size2;
	char	*new;
	int		i;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	new = malloc(sizeof(char) * (size1 + size2 + 1));
	if (!new)
		return (0);
	i = 0;
	while (s1 != NULL && i < size1)
	{
		new[i] = s1[i];
		i++;
	}
	while (s2 != NULL && (i - size1) < size2)
	{
		new[i] = s2[i - size1];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strchr(char *s)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == '\n')
			return (s + 1);
		s++;
	}
	return (NULL);
}

char	*ft_strdup(char *s)
{
	char	*new;
	int		i;

	if (s == NULL || *s == '\0')
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*extract_line(char	**plo)
{
	char	*line;

	line = ft_strdup(*plo);
	free(*plo);
	*plo = ft_strdup(ft_strchr(line));
	*(ft_strchr(line)) = '\0';
	return (line);
}
