/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:38:19 by oroy              #+#    #+#             */
/*   Updated: 2023/08/25 22:33:04 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "MLX42/MLX42.h"

typedef struct s_data
{
	int			player_on;
	int			exit_on;
	char		currentdir;
	int			movetotal;
	int			numtex;
	int			width;
	int			height;
	int			collectibles;
	int			collect_count;
	int			collect_onscreen;
	int			exitgood;
	int			px;
	int			x;
	int			y;
	char		**map;
	mlx_t		*mlx;
	mlx_image_t	**img;
}	t_data;

t_data	*g(void);
void	check_collectibles_attainability(char **map);
void	check_if_map_possible(void);
void	check_map_eligibility(char **map);
void	display_images(mlx_t *mlx, char **tab);
void	error(void);
void	flood_fill(void);
int		get_height(void);
int		get_width(void);
void	key_hooks(mlx_key_data_t keydata, void* param);
void	load_images(void);
void	loop_hook(void* param);
void	malloc_check(void *ptr);
void	print_err(char *msg);
void	read_map(char *file);
void	start_flooding(char **map, int x, int y);

#endif
