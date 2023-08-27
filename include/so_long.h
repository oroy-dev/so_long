/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:38:19 by oroy              #+#    #+#             */
/*   Updated: 2023/08/26 22:36:45 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "MLX42/MLX42.h"

typedef struct s_data
{
	char	**map;
	int		px;
	int		x;
	int		y;
	int		width;
	int		height;
	int		player_on;
	int		exit_on;
	int		movetotal;
	int		collectibles;
	int		collect_count;
	mlx_image_t	*currentdir;
	mlx_t	*mlx;
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
	mlx_image_t	*station;
	mlx_image_t	*wagon_h;
	mlx_image_t	*wagon_v;
}	t_img;

t_data	*td(void);
t_img	*ti(void);
void	check_collectibles_attainability(char **map);
void	check_if_map_possible(void);
void	check_map_eligibility(char **map);
void	display_images(char **tab, int px);
void	error(void);
void	flood_fill(void);
int		get_height(void);
int		get_width(void);
void	key_hooks(mlx_key_data_t keydata, void* param);
void	load_images(void);
void	loop_hook(void* param);
void	malloc_check(void *ptr);
void	mlx_error_check(void *ptr);
void	move_character(char key, int x, int y, int pos);
void	print_error(char *msg);
void	read_map(char *file);
void	start_flooding(char **map, int x, int y);

#endif
