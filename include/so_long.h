/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:38:19 by oroy              #+#    #+#             */
/*   Updated: 2023/08/15 20:12:29 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "MLX42/MLX42.h"

typedef struct s_data
{
	int				collect_count;
	int				pos_x;
	int				pos_y;
	int				move_px;
	char			**map;
	int				char_layer;
	mlx_t			*mlx;
	mlx_image_t		**img;
	mlx_image_t		*current_char;
	char			lastkey;
}	t_data;

#endif
