/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:38:19 by oroy              #+#    #+#             */
/*   Updated: 2023/08/18 15:24:36 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "MLX42/MLX42.h"

typedef struct s_data
{
	t_list		*lastpos;
	int			lastinst;
	int			numtex;
	int			width;
	int			height;
	int			move_px;
	int			lastlayer;
	int			collect_count;
	int			collect_onscreen;
	int			pos_x;
	int			pos_y;
	char		**map;
	mlx_t		*mlx;
	mlx_image_t	**img;
	mlx_image_t	*current_char;
	char		lastkey;
}	t_data;

t_data	*g(void);
int		display_images(mlx_t *mlx, char **tab);
void	error(void);
int		get_height(void);
int		get_width(void);
void	key_hooks(mlx_key_data_t keydata, void* param);
void	load_images(void);
void	malloc_check(void *maloc);
void	read_map(char *file);
void	update_pos(char key);

#endif
