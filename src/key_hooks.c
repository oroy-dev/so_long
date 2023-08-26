/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:03:38 by oroy              #+#    #+#             */
/*   Updated: 2023/08/23 18:02:51 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_key_index(char key)
{
	if (key == 'W')
		return (4);
	else if (key == 'D')
		return (5);
	else if (key == 'A')
		return (6);
	else
		return (3);
}

static void	update_pos(char key)
{
	int	key_idx;
	int	i;

	i = 0;
	key_idx = get_key_index(key);
	g()->img[key_idx]->instances[0].x = g()->x * g()->px;
	g()->img[key_idx]->instances[0].y = g()->y * g()->px;
	if (g()->currentdir != key)
	{
		g()->img[get_key_index(g()->currentdir)]->instances[0].enabled = false;
		g()->img[key_idx]->instances[0].enabled = true;
		g()->currentdir = key;
	}
	if (g()->map[g()->y][g()->x] == 'C')
	{
		while (i < g()->collect_count)
		{
			if (g()->img[10]->instances[i].x == g()->x * g()->px
				&& g()->img[10]->instances[i].y == g()->y * g()->px)
			{
				g()->img[10]->instances[i].z = -1;
				g()->img[11]->instances[i].z = -1;
				g()->map[g()->y][g()->x] = '0';
				g()->collect_onscreen--;
			}
			i++;
		}
		// if (g()->collect_onscreen == 0)
		// 	mlx_image_to_window(g()->mlx, g()->img[7], g()->ext[0] * g()->px, g()->ext[1] * g()->px);
	}
	else if (g()->map[g()->y][g()->x] == 'E' && !g()->collect_onscreen)
	{
		printf ("You won!");
		exit (EXIT_SUCCESS);
	}
}

static void	move_character(char key, int x, int y, int pos)
{
	(void) pos;
	if (key == 'W' || key == 'S')
		mlx_image_to_window(g()->mlx, g()->img[8], x * g()->px, y * g()->px);
	else
		mlx_image_to_window(g()->mlx, g()->img[7], x * g()->px, y * g()->px);
	g()->map[y][x] = 'Q';
	ft_printf ("%i\n", ++g()->movetotal);
	update_pos(key);
}

static int	check_collision(char tile)
{
	if (tile == '1' || tile == 'Q')
		return (1);
	return (0);
}

void	key_hooks(mlx_key_data_t keydata, void* param)
{
	(void) keydata;
	if ((mlx_is_key_down(param, MLX_KEY_UP)
		|| mlx_is_key_down(param, MLX_KEY_W))
		&& !check_collision(g()->map[g()->y - 1][g()->x]))
		move_character(MLX_KEY_W, g()->x, g()->y, g()->y--);
	else if ((mlx_is_key_down(param, MLX_KEY_DOWN)
		|| mlx_is_key_down(param, MLX_KEY_S))
		&& !check_collision(g()->map[g()->y + 1][g()->x]))
		move_character(MLX_KEY_S, g()->x, g()->y, g()->y++);
	else if ((mlx_is_key_down(param, MLX_KEY_RIGHT)
		|| mlx_is_key_down(param, MLX_KEY_D))
		&& !check_collision(g()->map[g()->y][g()->x + 1]))
		move_character(MLX_KEY_D, g()->x, g()->y, g()->x++);
	else if ((mlx_is_key_down(param, MLX_KEY_LEFT)
		|| mlx_is_key_down(param, MLX_KEY_A))
		&& !check_collision(g()->map[g()->y][g()->x - 1]))
		move_character(MLX_KEY_A, g()->x, g()->y, g()->x--);
	else if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
	{
		mlx_terminate(param);
		mlx_close_window(param);
		exit (EXIT_SUCCESS);
	}
}
