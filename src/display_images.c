/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:36:03 by oroy              #+#    #+#             */
/*   Updated: 2023/08/25 22:05:18 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_images(mlx_t *mlx, char **tab)
{
	int		row;
	int		col;

	row = 0;
	while (tab[row])
	{
		col = 0;
		while (tab[row][col])
		{
			if (tab[row][col] == '1')
			{
				if ((col * row) % 3 == 1)
					mlx_image_to_window(mlx, g()->img[2], col * g()->px, row * g()->px);
				else
					mlx_image_to_window(mlx, g()->img[1], col * g()->px, row * g()->px);
			}
			else
			{
				if ((col * row) % 2 == 1)
					mlx_image_to_window(mlx, g()->img[0], col * g()->px, row * g()->px);
				else
					mlx_image_to_window(mlx, g()->img[12], col * g()->px, row * g()->px);
			}
			if (tab[row][col] == 'C')
			{
				g()->collect_onscreen++;
				mlx_image_to_window(mlx, g()->img[10], col * g()->px, row * g()->px);
				mlx_image_to_window(mlx, g()->img[11], col * g()->px, row * g()->px);
			}
			else if (tab[row][col] == 'E')
				mlx_image_to_window(mlx, g()->img[9], col * g()->px, row * g()->px);
			col++;
		}
		row++;
	}
}
