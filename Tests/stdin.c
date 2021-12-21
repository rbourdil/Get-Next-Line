/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:32:25 by rbourdil          #+#    #+#             */
/*   Updated: 2021/12/20 16:14:23 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "get_next_line.h"

int	main()
{
	char	*line;
	char	*tabline[1000] = {NULL};
	int		i;

	i = 0;
	while ((line = get_next_line(0)))
	{
		tabline[i] = strdup(line);
		free(line);
		i++;
	}
	tabline[i] = NULL;
	i = 0;
	while (tabline[i] != NULL)
	{
		printf("%s", tabline[i]);
		free(tabline[i]);
		tabline[i] = NULL;
		i++;
	}
	return (0);
}
