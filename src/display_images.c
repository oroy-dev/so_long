/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:36:03 by oroy              #+#    #+#             */
/*   Updated: 2023/08/18 18:20:49 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_images(mlx_t *mlx, char **tab)
{
	int		row;
	int		col;
	int		layercount;
	int		inst;

	inst = 0;
	row = 0;
	layercount = 0;
	while (tab[row])
	{
		col = 0;
		while (tab[row][col])
		{
			if (tab[row][col] == '1')
				mlx_image_to_window(mlx, g()->img[1], col * g()->move_px, row * g()->move_px);
			else
				mlx_image_to_window(mlx, g()->img[0], col * g()->move_px, row * g()->move_px);
			if (tab[row][col] == 'C')
			{
				g()->collect_count++;
				g()->collect_onscreen++;
				mlx_image_to_window(mlx, g()->img[2], col * g()->move_px, row * g()->move_px);
			}
			else if (tab[row][col] == 'P')
			{
				inst = mlx_image_to_window(mlx, g()->img[3], col * g()->move_px, row * g()->move_px);
				g()->current_char = g()->img[3];
				g()->pos_x = col;
				g()->pos_y = row;
				g()->lastpos = ft_lstnew(row, col, inst, 3);
			}
			else if (tab[row][col] == 'E')
				mlx_image_to_window(mlx, g()->img[9], col * g()->move_px, row * g()->move_px);
			col++;
			layercount++;
		}
		row++;
	}
	return (layercount);
}
