/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:36:03 by oroy              #+#    #+#             */
/*   Updated: 2023/08/16 17:34:08 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_images(mlx_t *mlx, mlx_image_t *img[4], char **tab)
{
	int		row;
	int		col;
	int		layercount;

	row = 0;
	layercount = 0;
	while (tab[row])
	{
		col = 0;
		while (tab[row][col])
		{
			if (tab[row][col] == '1')
				mlx_image_to_window(mlx, img[1], col * g()->move_px, row * g()->move_px);
			else
				mlx_image_to_window(mlx, img[0], col * g()->move_px, row * g()->move_px);
			if (tab[row][col] == 'C')
			{
				g()->collect_count++;
				g()->collect_onscreen++;
				mlx_image_to_window(mlx, img[2], col * g()->move_px, row * g()->move_px);
			}
			else if (tab[row][col] == 'P')
			{
				mlx_image_to_window(mlx, img[3], col * g()->move_px, row * g()->move_px);
				g()->current_char = img[3];
				g()->pos_x = col;
				g()->pos_y = row;
			}
			else if (tab[row][col] == 'E')
			{
				g()->ext[0] = row;
				g()->ext[1] = col;
			}
			col++;
			layercount++;
		}
		row++;
	}
	return (layercount);
}
