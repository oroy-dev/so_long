/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:10:21 by oroy              #+#    #+#             */
/*   Updated: 2023/08/18 19:56:59 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	change_direction(mlx_image_t *img, char key)
// {
// 	if (g()->lastkey != key)
// 	{
// 		g()->current_char->instances[0].enabled = false;
// 		if (!img->instances)
// 			mlx_image_to_window(g()->mlx, img, g()->pos_x * g()->move_px, g()->pos_y * g()->move_px);
// 		else
// 			img->instances[0].enabled = true;
// 		g()->current_char = img;
// 		g()->lastkey = key;
// 	}
// 	img->instances[0].x = g()->pos_x * g()->move_px;
// 	img->instances[0].y = g()->pos_y * g()->move_px;
// }

void	update_pos(char key)
{
	int	i;
	int inst;

	i = 0;
	inst = 0;
	if (key == 'W')
	{
		// change_direction(g()->img[4], key);
		inst = mlx_image_to_window(g()->mlx, g()->img[4], g()->pos_x * g()->move_px, g()->pos_y * g()->move_px);
		ft_lstadd_front(&g()->lastpos, ft_lstnew(g()->pos_y, g()->pos_x, inst, 4));
	}
	else if (key == 'S')
	{
		// change_direction(g()->img[3], key);
		inst = mlx_image_to_window(g()->mlx, g()->img[3], g()->pos_x * g()->move_px, g()->pos_y * g()->move_px);
		ft_lstadd_front(&g()->lastpos, ft_lstnew(g()->pos_y, g()->pos_x, inst, 3));
	}
	else if (key == 'D')
	{
		// change_direction(g()->img[5], key);
		inst = mlx_image_to_window(g()->mlx, g()->img[5], g()->pos_x * g()->move_px, g()->pos_y * g()->move_px);
		ft_lstadd_front(&g()->lastpos, ft_lstnew(g()->pos_y, g()->pos_x, inst, 5));
	}
	else if (key == 'A')
	{
		// change_direction(g()->img[6], key);
		inst = mlx_image_to_window(g()->mlx, g()->img[6], g()->pos_x * g()->move_px, g()->pos_y * g()->move_px);
		ft_lstadd_front(&g()->lastpos, ft_lstnew(g()->pos_y, g()->pos_x, inst, 6));
	}
	if (g()->map[g()->pos_y][g()->pos_x] == 'C')
	{
		while (i < g()->collect_count)
		{
			if (g()->img[2]->instances[i].x == g()->pos_x * g()->move_px
				&& g()->img[2]->instances[i].y == g()->pos_y * g()->move_px)
			{
				g()->img[2]->instances[i].enabled = false;
				g()->map[g()->pos_y][g()->pos_x] = '0';
				g()->collect_onscreen--;
			}
			i++;
		}
		// if (g()->collect_onscreen == 0)
		// 	mlx_image_to_window(g()->mlx, g()->img[7], g()->ext[0] * g()->move_px, g()->ext[1] * g()->move_px);
	}
	else if (g()->map[g()->pos_y][g()->pos_x] == 'E' && !g()->collect_onscreen)
	{
		printf ("You won!");
		exit (EXIT_SUCCESS);
	}
}
