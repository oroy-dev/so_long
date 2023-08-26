/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:08:42 by oroy              #+#    #+#             */
/*   Updated: 2023/08/25 22:14:47 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*get_tex_path(int i)
{
	if (i == 1)
		return ("./ressources/train/tile_mountain.png");
	else if (i == 2)
		return ("./ressources/train/tile_tree.png");
	else if (i == 3)
		return ("./ressources/train/train_f.png");
	else if (i == 4)
		return ("./ressources/train/train_b.png");
	else if (i == 5)
		return ("./ressources/train/train_r.png");
	else if (i == 6)
		return ("./ressources/train/train_l.png");
	else if (i == 7)
		return ("./ressources/train/wagon_hori.png");
	else if (i == 8)
		return ("./ressources/train/wagon_vert.png");
	else if (i == 9)
		return ("./ressources/train/train_station.png");
	else if (i == 10)
		return ("./ressources/train/light_l.png");
	else if (i == 11)
		return ("./ressources/train/light_r.png");
	else if (i == 12)
		return ("./ressources/train/tile_grass_2.png");
	else
		return ("./ressources/train/tile_grass.png");
}

void	load_images(void)
{
	mlx_texture_t	*tex;
	char			*texpath;
	int				i;

	i = 0;
	g()->img = ft_calloc(g()->numtex, sizeof (mlx_texture_t *));
	malloc_check(g()->img);
	while (i < g()->numtex)
	{
		texpath = ft_strdup(get_tex_path(i));
		malloc_check(texpath);
		tex = mlx_load_png(texpath);
		ft_free(texpath);
		if (!tex)
			error();
		g()->img[i] = mlx_texture_to_image(g()->mlx, tex);
		if (!g()->img[i])
			error();
		i++;
	}
}
