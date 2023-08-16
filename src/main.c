/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:42:12 by oroy              #+#    #+#             */
/*   Updated: 2023/08/16 17:36:36 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(void)
{
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
	exit (EXIT_FAILURE);
}

void	change_direction(mlx_image_t *img, char key)
{
	if (g()->lastkey != key)
	{
		g()->current_char->instances[0].enabled = false;
		if (!img->instances)
			mlx_image_to_window(g()->mlx, img, g()->pos_x * g()->move_px, g()->pos_y * g()->move_px);
		else
			img->instances[0].enabled = true;
		g()->current_char = img;
		g()->lastkey = key;
	}
	img->instances[0].x = g()->pos_x * g()->move_px;
	img->instances[0].y = g()->pos_y * g()->move_px;
}

void	update_pos(char key)
{
	int	i;

	i = 0;
	if (key == 'W')
		change_direction(g()->img[4], key);
	else if (key == 'S')
		change_direction(g()->img[3], key);
	else if (key == 'D')
		change_direction(g()->img[5], key);
	else if (key == 'A')
		change_direction(g()->img[6], key);
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
		if (g()->collect_onscreen == 0)
			mlx_image_to_window(g()->mlx, g()->img[7], g()->ext[0] * g()->move_px, g()->ext[1] * g()->move_px);
	}
	else if (g()->map[g()->pos_y][g()->pos_x] == 'E' && !g()->collect_onscreen)
	{
		printf ("You won!");
		exit (EXIT_SUCCESS);
	}
}

void	key_hooks(mlx_key_data_t keydata, void* param)
{
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && keydata.action == MLX_PRESS
		&& g()->map[g()->pos_y - 1][g()->pos_x] != '1')
	{
		g()->pos_y--;
		update_pos('W');
	}
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) && keydata.action == MLX_PRESS
		&& g()->map[g()->pos_y + 1][g()->pos_x] != '1')
	{
		g()->pos_y++;
		update_pos('S');
	}
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) && keydata.action == MLX_PRESS
		&& g()->map[g()->pos_y][g()->pos_x + 1] != '1')
	{
		g()->pos_x++;
		update_pos('D');
	}
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) && keydata.action == MLX_PRESS
		&& g()->map[g()->pos_y][g()->pos_x - 1] != '1')
	{
		g()->pos_x--;
		update_pos('A');
	}
	(void) param;
	// *(int *)param += 1;
	// printf ("%i\n", *(int *)param);
}

int	main(int argc, char **argv)
{
	int	character_layer;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n Make sure to have 2 arguments precisely.\n", 2);
		exit (EXIT_FAILURE);
	}
	read_map(argv[1]);
	g()->mlx = mlx_init(get_width(), get_height(), "so_long", false);
	if (!g()->mlx)
		error();
	load_images();
	character_layer = display_images(g()->mlx, g()->img, g()->map);
	mlx_set_instance_depth(g()->img[3]->instances, character_layer);
	mlx_key_hook(g()->mlx, &key_hooks, NULL);
	mlx_loop(g()->mlx);
	mlx_terminate(g()->mlx);
	return (0);
}
