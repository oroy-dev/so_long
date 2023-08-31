/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:42:12 by oroy              #+#    #+#             */
/*   Updated: 2023/08/31 17:18:33 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*ti(void)
{
	static t_img	ti;

	return (&ti);
}

t_data	*td(void)
{
	static t_data	td;

	if (!td.px)
	{
		td.px = 64;
		td.width = 0;
		td.height = 0;
		td.player_on = 0;
		td.exit_on = 0;
		td.movetotal = 0;
		td.collect = 0;
		td.collectotal = 0;
		td.text = NULL;
	}
	return (&td);
}

static void	init_character(int x, int y)
{
	mlx_image_to_window(td()->mlx, ti()->train_f, x, y);
	mlx_image_to_window(td()->mlx, ti()->train_b, x, y);
	mlx_image_to_window(td()->mlx, ti()->train_r, x, y);
	mlx_image_to_window(td()->mlx, ti()->train_l, x, y);
	ti()->train_b->instances[0].enabled = false;
	ti()->train_r->instances[0].enabled = false;
	ti()->train_l->instances[0].enabled = false;
	td()->currentdir = ti()->train_f;
}

int	main(int argc, char **argv)
{
	mlx_t	*mlx;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nMake sure to have 2 arguments precisely.\n", 2);
		exit (EXIT_FAILURE);
	}
	read_map(argv[1]);
	check_map_eligibility(td()->map);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	mlx = mlx_init(get_width(), get_height() + td()->px, "so_long", true);
	mlx_error_check(mlx);
	td()->mlx = mlx;
	load_images();
	display_images(td()->map, td()->px);
	init_character(td()->x * td()->px, td()->y * td()->px);
	display_movetotal_bonus(td()->px);
	mlx_loop_hook(td()->mlx, loop_hook, td()->mlx);
	mlx_key_hook(td()->mlx, &key_hooks_bonus, td()->mlx);
	mlx_loop(td()->mlx);
	mlx_terminate(td()->mlx);
	ft_free_tab(td()->map);
	return (0);
}
