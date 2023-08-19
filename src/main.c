/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:42:12 by oroy              #+#    #+#             */
/*   Updated: 2023/08/18 18:05:18 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*g(void)
{
	static t_data	ptr;

	if (!ptr.move_px)
	{
		ptr.lastpos = NULL;
		ptr.lastinst = 0;
		ptr.move_px = 64;
		ptr.numtex = 10;
		ptr.width = 0;
		ptr.height = 0;
		ptr.lastkey = 'S';
		ptr.collect_count = 0;
		ptr.collect_onscreen = 0;
		ptr.lastlayer = 0;
	}
	return (&ptr);
}

int	main(int argc, char **argv)
{
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
	g()->lastlayer = display_images(g()->mlx, g()->map);
	mlx_set_instance_depth(g()->img[3]->instances, g()->lastlayer);
	mlx_key_hook(g()->mlx, &key_hooks, g()->mlx);
	mlx_loop(g()->mlx);
	mlx_terminate(g()->mlx);
	return (0);
}
