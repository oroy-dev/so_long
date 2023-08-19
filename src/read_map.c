/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:17:53 by oroy              #+#    #+#             */
/*   Updated: 2023/08/17 16:04:41 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	file_to_tab(int fd)
{
	char	*gnl;
	char	*str;
	char	*temp;
	
	str = NULL;
	gnl = get_next_line(fd);
	while (gnl)
	{
		if (!str)
			str = ft_strdup(gnl);
		else
		{
			temp = ft_strdup(str);
			ft_free(str);
			str = ft_strjoin(temp, gnl);
			ft_free(temp);
		}
		ft_free(gnl);
		gnl = get_next_line(fd);
		g()->height++;
	}
	g()->map = ft_split(str, '\n');
	ft_free(gnl);
	ft_free(str);
}

void	read_map(char *file)
{
	int	fd;

	fd = open (file, O_RDONLY);
	if (fd == -1)
	{
		perror ("Error\n");
		exit (EXIT_FAILURE);
	}
	file_to_tab(fd);
	close (fd);
}
