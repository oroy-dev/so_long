/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:42:12 by oroy              #+#    #+#             */
/*   Updated: 2023/08/25 22:34:37 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*g(void)
{
	static t_data	ptr;

	if (!ptr.px)
	{
		ptr.player_on = 0;
		ptr.exit_on = 0;
		ptr.currentdir = 'S';
		ptr.movetotal = 0;
		ptr.px = 64;
		ptr.numtex = 13;
		ptr.width = 0;
		ptr.height = 0;
		ptr.collectibles = 0;
		ptr.collect_count = 0;
		ptr.collect_onscreen = 0;
		ptr.exitgood = 0;
		ptr.x = 0;
		ptr.y = 0;
		ptr.map = NULL;
		ptr.mlx = NULL;
		ptr.img = NULL;
	}
	return (&ptr);
}

static void	init_character(int x, int y)
{
	mlx_image_to_window(g()->mlx, g()->img[3], x, y);
	mlx_image_to_window(g()->mlx, g()->img[4], x, y);
	mlx_image_to_window(g()->mlx, g()->img[5], x, y);
	mlx_image_to_window(g()->mlx, g()->img[6], x, y);
	g()->img[4]->instances[0].enabled = false;
	g()->img[5]->instances[0].enabled = false;
	g()->img[6]->instances[0].enabled = false;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\nMake sure to have 2 arguments precisely.\n", 2);
		exit (EXIT_FAILURE);
	}
	read_map(argv[1]);
	check_map_eligibility(g()->map);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	g()->mlx = mlx_init(get_width(), get_height(), "so_long", true);
	if (!g()->mlx)
		error();
	load_images();
	display_images(g()->mlx, g()->map);
	init_character(g()->x * g()->px, g()->y * g()->px);
	mlx_loop_hook(g()->mlx, loop_hook, g()->mlx);
	mlx_key_hook(g()->mlx, &key_hooks, g()->mlx);
	mlx_loop(g()->mlx);
	mlx_terminate(g()->mlx);
	return (0);
}
