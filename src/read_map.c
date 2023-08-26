/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:17:53 by oroy              #+#    #+#             */
/*   Updated: 2023/08/25 22:35:31 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	null_check(char *str, char *gnl)
{
	if (!str)
	{
		ft_putendl_fd("Error\nMalloc failed", 2);
		ft_free(gnl);
		exit (EXIT_FAILURE);
	}
}

static char	*ft_strdup_join(char *str, char *gnl)
{
	char	*temp;

	temp = ft_strdup(str);
	ft_free(str);
	null_check(temp, gnl);
	str = ft_strjoin(temp, gnl);
	ft_free(temp);
	null_check(str, gnl);
	return (str);
}

static void	file_to_tab(int fd)
{
	char	*gnl;
	char	*str;
	
	str = NULL;
	gnl = get_next_line(fd);
	g()->width = ft_strlen(gnl);
	while (gnl)
	{
		if (!str)
		{
			str = ft_strdup(gnl);
			null_check(str, gnl);
		}
		else
			str = ft_strdup_join(str, gnl);
		ft_free(gnl);
		g()->height++;
		gnl = get_next_line(fd);
	}
	g()->map = ft_split(str, '\n');
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
