/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:03:38 by oroy              #+#    #+#             */
/*   Updated: 2023/08/28 13:33:47 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static int	check_collision(char tile)
// {
// 	if (tile == '1')
// 		return (1);
// 	return (0);
// }

void	key_hooks(mlx_key_data_t keydata, void *param)
{
	(void) keydata;
	if ((mlx_is_key_down(param, MLX_KEY_UP) 
			|| mlx_is_key_down(param, MLX_KEY_W))
		&& td()->map[td()->y - 1][td()->x] != '1')
		move_character(MLX_KEY_W, td()->x, td()->y, td()->y--);
	else if ((mlx_is_key_down(param, MLX_KEY_DOWN)
			|| mlx_is_key_down(param, MLX_KEY_S))
		&& td()->map[td()->y + 1][td()->x] != '1')
		move_character(MLX_KEY_S, td()->x, td()->y, td()->y++);
	else if ((mlx_is_key_down(param, MLX_KEY_RIGHT)
			|| mlx_is_key_down(param, MLX_KEY_D))
		&& td()->map[td()->y][td()->x + 1] != '1')
		move_character(MLX_KEY_D, td()->x, td()->y, td()->x++);
	else if ((mlx_is_key_down(param, MLX_KEY_LEFT)
			|| mlx_is_key_down(param, MLX_KEY_A))
		&& td()->map[td()->y][td()->x - 1] != '1')
		move_character(MLX_KEY_A, td()->x, td()->y, td()->x--);
	else if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
	{
		mlx_terminate(param);
		ft_free_tab(td()->map);
		exit (EXIT_SUCCESS);
	}
}
