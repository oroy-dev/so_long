/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:47:29 by oroy              #+#    #+#             */
/*   Updated: 2023/08/25 22:33:48 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill_square(char **map, int x, int y)
{
	if (map[y][x] == 'C')
		g()->collectibles++;
	else if (map[y][x] == 'E')
		g()->exitgood = 1;
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
	mapcopy = ft_calloc(g()->height + 1, sizeof (char *));
	malloc_check(mapcopy);
	while (i < g()->height)
	{
		mapcopy[i] = ft_strdup(g()->map[i]);
		malloc_check(mapcopy[i]);
		i++;
	}
	start_flooding(mapcopy, g()->x, g()->y);
	ft_free_tab(mapcopy);
	if (!g()->exitgood || g()->collectibles != g()->collect_count)
		print_err("Error\nMap not feasible");
}
