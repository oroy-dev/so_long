/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:08:42 by oroy              #+#    #+#             */
/*   Updated: 2023/08/31 14:27:16 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_image_t	*get_image(char *texpath)
{
	mlx_texture_t	*tex;
	mlx_image_t		*img;

	tex = mlx_load_png(texpath);
	mlx_error_check(tex);
	img = mlx_texture_to_image(td()->mlx, tex);
	mlx_delete_texture(tex);
	mlx_error_check(img);
	return (img);
}

void	load_images(void)
{
	ti()->grass = get_image("./ressources/train/grass.png");
	ti()->grass_2 = get_image("./ressources/train/grass_2.png");
	ti()->light_l = get_image("./ressources/train/light_l.png");
	ti()->light_r = get_image("./ressources/train/light_r.png");
	ti()->mountain = get_image("./ressources/train/mountain.png");
	ti()->train_b = get_image("./ressources/train/train_b.png");
	ti()->train_f = get_image("./ressources/train/train_f.png");
	ti()->train_l = get_image("./ressources/train/train_l.png");
	ti()->train_r = get_image("./ressources/train/train_r.png");
	ti()->station_off = get_image("./ressources/train/station_off.png");
	ti()->station_on = get_image("./ressources/train/station_on.png");
	ti()->tree = get_image("./ressources/train/tree.png");
	ti()->wagon_h = get_image("./ressources/train/wagon_h.png");
	ti()->wagon_v = get_image("./ressources/train/wagon_v.png");
}
