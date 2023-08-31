/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:03:38 by oroy              #+#    #+#             */
/*   Updated: 2023/08/31 16:02:51 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	trigger_hook(char key, int x, int y, int pos)
{
	int	px;

	(void) pos;
	px = td()->px;
	td()->map[y][x] = '1';
	if (key == 'W' || key == 'S')
		mlx_image_to_window(td()->mlx, ti()->wagon_v, x * px, y * px);
	else
		mlx_image_to_window(td()->mlx, ti()->wagon_h, x * px, y * px);
	ft_printf ("%i\n", ++td()->movetotal);
	display_movetotal_bonus(px);
	move_character(key);
}

void	key_hooks_bonus(mlx_key_data_t keydata, void *param)
{
	(void) keydata;
	if ((mlx_is_key_down(param, MLX_KEY_UP) 
			|| mlx_is_key_down(param, MLX_KEY_W))
		&& td()->map[td()->y - 1][td()->x] != '1')
		trigger_hook(MLX_KEY_W, td()->x, td()->y, td()->y--);
	else if ((mlx_is_key_down(param, MLX_KEY_DOWN)
			|| mlx_is_key_down(param, MLX_KEY_S))
		&& td()->map[td()->y + 1][td()->x] != '1')
		trigger_hook(MLX_KEY_S, td()->x, td()->y, td()->y++);
	else if ((mlx_is_key_down(param, MLX_KEY_RIGHT)
			|| mlx_is_key_down(param, MLX_KEY_D))
		&& td()->map[td()->y][td()->x + 1] != '1')
		trigger_hook(MLX_KEY_D, td()->x, td()->y, td()->x++);
	else if ((mlx_is_key_down(param, MLX_KEY_LEFT)
			|| mlx_is_key_down(param, MLX_KEY_A))
		&& td()->map[td()->y][td()->x - 1] != '1')
		trigger_hook(MLX_KEY_A, td()->x, td()->y, td()->x--);
	else if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
}
