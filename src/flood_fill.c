/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:47:29 by oroy              #+#    #+#             */
/*   Updated: 2023/08/30 15:33:45 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill_square(char **map, int x, int y)
{
	if (map[y][x] == 'C')
		td()->collect++;
	else if (map[y][x] == 'E')
		td()->exit_on = 0;
	map[y][x] = '+';
	start_flooding(map, x, y);
}

void	start_flooding(char **map, int x, int y)
{
	if (map[y - 1][x] != '1' && map[y - 1][x] != '+')
		fill_square(map, x, y - 1);
	if (map[y][x + 1] != '1' && map[y][x + 1] != '+')
		fill_square(map, x + 1, y);
	if (map[y + 1][x] != '1' && map[y + 1][x] != '+')
		fill_square(map, x, y + 1);
	if (map[y][x - 1] != '1' && map[y][x - 1] != '1')
		fill_square(map, x - 1, y);
}

void	flood_fill(void)
{
	char	**mapcopy;
	int		i;

	i = 0;
	mapcopy = ft_calloc(td()->height + 1, sizeof (char *));
	if (!mapcopy)
		print_error("Error\nMalloc failed");
	while (i < td()->height)
	{
		mapcopy[i] = ft_strdup(td()->map[i]);
		if (!mapcopy[i])
		{
			ft_free_tab(mapcopy);
			print_error("Error\nMalloc failed");
		}
		i++;
	}
	start_flooding(mapcopy, td()->x, td()->y);
	ft_free_tab(mapcopy);
	if (td()->exit_on || td()->collect != td()->collectotal)
		print_error("Error\nMap not feasible");
}
