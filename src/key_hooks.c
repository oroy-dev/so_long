/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:03:38 by oroy              #+#    #+#             */
/*   Updated: 2023/08/19 15:01:47 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printmap(void)
{
	int	i;
	int	j;

	i = 0;
	while (g()->map[i])
	{
		j = 0;
		while (g()->map[i][j])
		{
			printf ("%c", g()->map[i][j]);
			j++;
		}
		printf ("\n");
		i++;
	}
	printf ("\n");
}

void	key_hooks(mlx_key_data_t keydata, void* param)
{
	t_list	*next;

	(void) keydata;
	if ((mlx_is_key_down(param, MLX_KEY_UP) || mlx_is_key_down(param, MLX_KEY_W))
		&& g()->map[g()->pos_y - 1][g()->pos_x] != '1')
	{
		if (g()->map[g()->pos_y - 1][g()->pos_x] != 'Q')
		{
			g()->img[g()->lastpos->direction]->instances[g()->lastpos->inst].enabled = false;
			g()->lastpos->inst = mlx_image_to_window(g()->mlx, g()->img[8], g()->pos_x * g()->move_px, g()->pos_y * g()->move_px);
			g()->lastpos->direction = 8;
			g()->map[g()->pos_y][g()->pos_x] = 'Q';
			g()->pos_y--;
			update_pos('W');
		}
		else if (g()->pos_y - 1 == g()->lastpos->next->pos_y)
		{
			next = g()->lastpos->next;
			g()->img[next->direction]->instances[next->inst].enabled = false;
			g()->map[g()->pos_y][g()->pos_x] = '0';
			g()->pos_y--;
			g()->lastpos->next = next->next;
			next->next = NULL;
			ft_free(next);
			if (g()->lastpos->direction == 3)
			{
				g()->lastpos->pos_y = g()->pos_y;
				g()->img[g()->lastpos->direction]->instances[g()->lastpos->inst].y -= g()->move_px;
			}
			else
			{
				g()->img[g()->lastpos->direction]->instances[g()->lastpos->inst].enabled = false;
				g()->lastpos->inst = mlx_image_to_window(g()->mlx, g()->img[3], g()->pos_x * g()->move_px, g()->pos_y * g()->move_px);
				g()->lastpos->direction = 3;
			}
		}
	}
	else if ((mlx_is_key_down(param, MLX_KEY_DOWN) || mlx_is_key_down(param, MLX_KEY_S))
		&& g()->map[g()->pos_y + 1][g()->pos_x] != '1')
	{
		if (g()->map[g()->pos_y + 1][g()->pos_x] != 'Q')
		{
			g()->img[g()->lastpos->direction]->instances[g()->lastpos->inst].enabled = false;
			g()->lastpos->inst = mlx_image_to_window(g()->mlx, g()->img[8], g()->pos_x * g()->move_px, g()->pos_y * g()->move_px);
			g()->lastpos->direction = 8;
			printf ("%i\n", g()->lastpos->direction);
			g()->map[g()->pos_y][g()->pos_x] = 'Q';
			g()->pos_y++;
			update_pos('S');
		}
		else if (g()->pos_y + 1 == g()->lastpos->next->pos_y)
		{
			next = g()->lastpos->next;
			g()->img[next->direction]->instances[next->inst].enabled = false;
			g()->map[g()->pos_y][g()->pos_x] = '0';
			g()->pos_y++;
			g()->lastpos->next = next->next;
			next->next = NULL;
			ft_free(next);
			if (g()->lastpos->direction == 4)
			{
				g()->lastpos->pos_y = g()->pos_y;
				g()->img[g()->lastpos->direction]->instances[g()->lastpos->inst].y += g()->move_px;
			}
			else
			{
				g()->img[g()->lastpos->direction]->instances[g()->lastpos->inst].enabled = false;
				g()->lastpos->inst = mlx_image_to_window(g()->mlx, g()->img[4], g()->pos_x * g()->move_px, g()->pos_y * g()->move_px);
				g()->lastpos->direction = 4;
			}
		}
	}
	else if ((mlx_is_key_down(param, MLX_KEY_RIGHT) || mlx_is_key_down(param, MLX_KEY_D))
		&& g()->map[g()->pos_y][g()->pos_x + 1] != '1')
	{
		if (g()->map[g()->pos_y][g()->pos_x + 1] != 'Q')
		{
			g()->img[g()->lastpos->direction]->instances[g()->lastpos->inst].enabled = false;
			g()->lastpos->inst = mlx_image_to_window(g()->mlx, g()->img[7], g()->pos_x * g()->move_px, g()->pos_y * g()->move_px);
			g()->lastpos->direction = 7;
			g()->map[g()->pos_y][g()->pos_x] = 'Q';
			g()->pos_x++;
			update_pos('D');
		}
		else if (g()->pos_x + 1 == g()->lastpos->next->pos_x)
		{
			next = g()->lastpos->next;
			g()->img[next->direction]->instances[next->inst].enabled = false;
			g()->map[g()->pos_y][g()->pos_x] = '0';
			g()->pos_x++;
			g()->lastpos->next = next->next;
			next->next = NULL;
			ft_free(next);
			if (g()->lastpos->direction == 6)
			{
				g()->lastpos->pos_x = g()->pos_x;
				g()->img[g()->lastpos->direction]->instances[g()->lastpos->inst].x += g()->move_px;
			}
			else
			{
				g()->img[g()->lastpos->direction]->instances[g()->lastpos->inst].enabled = false;
				g()->lastpos->inst = mlx_image_to_window(g()->mlx, g()->img[6], g()->pos_x * g()->move_px, g()->pos_y * g()->move_px);
				g()->lastpos->direction = 6;
			}
		}
	}
	else if ((mlx_is_key_down(param, MLX_KEY_LEFT) || mlx_is_key_down(param, MLX_KEY_A))
		&& g()->map[g()->pos_y][g()->pos_x - 1] != '1')
	{
		if (g()->map[g()->pos_y][g()->pos_x - 1] != 'Q')
		{
			g()->img[g()->lastpos->direction]->instances[g()->lastpos->inst].enabled = false;
			g()->lastpos->inst = mlx_image_to_window(g()->mlx, g()->img[7], g()->pos_x * g()->move_px, g()->pos_y * g()->move_px);
			g()->lastpos->direction = 7;
			g()->map[g()->pos_y][g()->pos_x] = 'Q';
			g()->pos_x--;
			update_pos('A');
		}
		else if (g()->pos_x - 1 == g()->lastpos->next->pos_x)
		{
			next = g()->lastpos->next;
			g()->img[next->direction]->instances[next->inst].enabled = false;
			g()->map[g()->pos_y][g()->pos_x] = '0';
			g()->pos_x--;
			g()->lastpos->next = next->next;
			next->next = NULL;
			ft_free(next);
			if (g()->lastpos->direction == 5)
			{
				g()->lastpos->pos_x = g()->pos_x;
				g()->img[g()->lastpos->direction]->instances[g()->lastpos->inst].x -= g()->move_px;
			}
			else
			{
				g()->img[g()->lastpos->direction]->instances[g()->lastpos->inst].enabled = false;
				g()->lastpos->inst = mlx_image_to_window(g()->mlx, g()->img[5], g()->pos_x * g()->move_px, g()->pos_y * g()->move_px);
				g()->lastpos->direction = 5;
			}
		}
	}
	else if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
	{
		mlx_terminate(param);
		mlx_close_window(param);
		exit (EXIT_SUCCESS);
	}
}
