/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:03:38 by oroy              #+#    #+#             */
/*   Updated: 2023/08/30 16:07:56 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	trigger_hook(char key, int pos)
{
	(void) pos;
	ft_printf ("%i\n", ++td()->movetotal);
	move_character(key);
}

void	key_hooks(mlx_key_data_t keydata, void *param)
{
	(void) keydata;
	if ((mlx_is_key_down(param, MLX_KEY_UP) 
			|| mlx_is_key_down(param, MLX_KEY_W))
		&& td()->map[td()->y - 1][td()->x] != '1')
		trigger_hook(MLX_KEY_W, td()->y--);
	else if ((mlx_is_key_down(param, MLX_KEY_DOWN)
			|| mlx_is_key_down(param, MLX_KEY_S))
		&& td()->map[td()->y + 1][td()->x] != '1')
		trigger_hook(MLX_KEY_S, td()->y++);
	else if ((mlx_is_key_down(param, MLX_KEY_RIGHT)
			|| mlx_is_key_down(param, MLX_KEY_D))
		&& td()->map[td()->y][td()->x + 1] != '1')
		trigger_hook(MLX_KEY_D, td()->x++);
	else if ((mlx_is_key_down(param, MLX_KEY_LEFT)
			|| mlx_is_key_down(param, MLX_KEY_A))
		&& td()->map[td()->y][td()->x - 1] != '1')
		trigger_hook(MLX_KEY_A, td()->x--);
	else if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
}
