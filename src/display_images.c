/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:36:03 by oroy              #+#    #+#             */
/*   Updated: 2023/08/30 16:17:55 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	place_items(char c, int x, int y, int px)
{
	if (c == '1')
	{
		if ((x * y) % 3 == 1)
			mlx_image_to_window(td()->mlx, ti()->tree, x * px, y * px);
		else
			mlx_image_to_window(td()->mlx, ti()->mountain, x * px, y * px);
	}
	else
	{
		if ((x * y) % 3 == 1)
			mlx_image_to_window(td()->mlx, ti()->grass, x * px, y * px);
		else
			mlx_image_to_window(td()->mlx, ti()->grass_2, x * px, y * px);
	}
	if (c == 'C')
	{
		mlx_image_to_window(td()->mlx, ti()->light_l, x * px, y * px);
		mlx_image_to_window(td()->mlx, ti()->light_r, x * px, y * px);
	}
	else if (c == 'E')
	{
		mlx_image_to_window(td()->mlx, ti()->station_on, x * px, y * px);
		mlx_image_to_window(td()->mlx, ti()->station_off, x * px, y * px);
	}
}

void	display_images(char **tab, int px)
{
	int		y;
	int		x;

	y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			place_items(tab[y][x], x, y, px);
			x++;
		}
		y++;
	}
}
