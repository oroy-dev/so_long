/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:38:19 by oroy              #+#    #+#             */
/*   Updated: 2023/08/31 16:02:30 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "MLX42/MLX42.h"

typedef struct s_data
{
	char		**map;
	int			px;
	int			x;
	int			y;
	int			width;
	int			height;
	int			player_on;
	int			exit_on;
	int			movetotal;
	int			collect;
	int			collectotal;
	mlx_image_t	*currentdir;
	mlx_image_t	*text;
	mlx_t		*mlx;
}	t_data;

typedef struct s_img
{
	mlx_image_t	*grass;
	mlx_image_t	*grass_2;
	mlx_image_t	*light_l;
	mlx_image_t	*light_r;
	mlx_image_t	*mountain;
	mlx_image_t	*train_b;
	mlx_image_t	*train_f;
	mlx_image_t	*train_l;
	mlx_image_t	*train_r;
	mlx_image_t	*tree;
	mlx_image_t	*station_off;
	mlx_image_t	*station_on;
	mlx_image_t	*wagon_h;
	mlx_image_t	*wagon_v;
}	t_img;

t_data	*td(void);
t_img	*ti(void);
void	check_map_eligibility(char **map);
void	display_images(char **tab, int px);
void	display_movetotal_bonus(int px);
void	flood_fill(void);
int		get_height(void);
int		get_width(void);
void	key_hooks(mlx_key_data_t keydata, void *param);
void	key_hooks_bonus(mlx_key_data_t keydata, void *param);
void	load_images(void);
void	loop_hook(void *param);
void	mlx_error_check(void *ptr);
void	move_character(char key);
void	print_error(char *msg);
void	read_map(char *file);
void	start_flooding(char **map, int x, int y);

#endif
