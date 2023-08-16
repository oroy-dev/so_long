/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:08:42 by oroy              #+#    #+#             */
/*   Updated: 2023/08/16 17:28:06 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*get_tex_path(int i)
{
	if (i == 1)
		return ("./ressources/test/tile_mountain.png");
	else if (i == 2)
		return ("./ressources/test/collectible.png");
	else if (i == 3)
		return ("./ressources/test/char_front.png");
	else if (i == 4)
		return ("./ressources/test/char_back.png");
	else if (i == 5)
		return ("./ressources/test/char_right.png");
	else if (i == 6)
		return ("./ressources/test/char_left.png");
	else if (i == 7)
		return ("./ressources/test/exit.png");
	else
		return ("./ressources/test/tile_grass.png");
}

void	load_images(void)
{
	mlx_texture_t	*tex;
	char			*texpath;
	int				i;

	i = 0;
	g()->img = ft_calloc(g()->numtex + 1, sizeof (mlx_texture_t *));
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
