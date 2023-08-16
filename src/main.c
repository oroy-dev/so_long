/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:42:12 by oroy              #+#    #+#             */
/*   Updated: 2023/08/15 20:27:03 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*g(void)
{
	static t_data	ptr;

	return (&ptr);
}

static void	error(void)
{
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
	exit (EXIT_FAILURE);
}

void	change_direction(mlx_image_t *img, char key)
{
	if (g()->lastkey != key)
	{
		g()->current_char->instances[0].enabled = false;
		if (!img->instances)
			mlx_image_to_window(g()->mlx, img, g()->pos_x * g()->move_px, g()->pos_y * g()->move_px);
		else
			img->instances[0].enabled = true;
		g()->current_char = img;
		g()->lastkey = key;
	}
	img->instances[0].x = g()->pos_x * g()->move_px;
	img->instances[0].y = g()->pos_y * g()->move_px;
}

void	update_pos(char key)
{
	int	i;

	i = 0;
	if (key == 'W')
		change_direction(g()->img[4], key);
	else if (key == 'S')
		change_direction(g()->img[3], key);
	else if (key == 'D')
		change_direction(g()->img[5], key);
	else if (key == 'A')
		change_direction(g()->img[6], key);
	if (g()->map[g()->pos_y][g()->pos_x] == 'C')
	{
		while (i < g()->collect_count)
		{
			if (g()->img[2]->instances[i].x == g()->pos_x * g()->move_px
				&& g()->img[2]->instances[i].y == g()->pos_y * g()->move_px)
				g()->img[2]->instances[i].enabled = false;
			i++;
		}
	}
}

void	key_hooks(mlx_key_data_t keydata, void* param)
{
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && keydata.action == MLX_PRESS
		&& g()->map[g()->pos_y - 1][g()->pos_x] != '1')
	{
		g()->pos_y--;
		update_pos('W');
	}
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) && keydata.action == MLX_PRESS
		&& g()->map[g()->pos_y + 1][g()->pos_x] != '1')
	{
		g()->pos_y++;
		update_pos('S');
	}
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) && keydata.action == MLX_PRESS
		&& g()->map[g()->pos_y][g()->pos_x + 1] != '1')
	{
		g()->pos_x++;
		update_pos('D');
	}
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) && keydata.action == MLX_PRESS
		&& g()->map[g()->pos_y][g()->pos_x - 1] != '1')
	{
		g()->pos_x--;
		update_pos('A');
	}
	*(int *)param += 1;
	printf ("%i\n", *(int *)param);
}

int	parse_img(mlx_t *mlx, mlx_image_t *img[4], char **tab)
{
	int		layercount;
	int		row;
	int		col;

	row = 0;
	layercount = 0;
	while (tab[row])
	{
		col = 0;
		while (tab[row][col])
		{
			if (tab[row][col] == '1')
				mlx_image_to_window(mlx, img[1], col * g()->move_px, row * g()->move_px);
			else
				mlx_image_to_window(mlx, img[0], col * g()->move_px, row * g()->move_px);
			if (tab[row][col] == 'C')
			{
				g()->collect_count++;
				mlx_image_to_window(mlx, img[2], col * g()->move_px, row * g()->move_px);
			}
			else if (tab[row][col] == 'P')
			{
				mlx_image_to_window(mlx, img[3], col * g()->move_px, row * g()->move_px);
				g()->current_char = img[3];
				g()->pos_x = col;
				g()->pos_y = row;
			}
			layercount++;
			col++;
		}
		row++;
	}
	return (layercount);
}

char	*get_tex_path(int i)
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
	else
		return ("./ressources/test/tile_grass.png");
}

void	file_to_tab(int fd)
{
	char	*gnl;
	char	*str;
	char	*temp;
	
	str = NULL;
	gnl = get_next_line(fd);
	while (gnl)
	{
		if (!str)
			str = ft_strdup(gnl);
		else
		{
			temp = ft_strdup(str);
			ft_free(str);
			str = ft_strjoin(temp, gnl);
			ft_free(temp);
		}
		ft_free(gnl);
		gnl = get_next_line(fd);
	}
	g()->map = ft_split(str, '\n');
	ft_free(gnl);
	ft_free(str);
}

int	main(int argc, char **argv)
{
	mlx_texture_t	*tex;
	char			*texpath;
	int				numtex;
	int				total;
	int				fd;
	int				i;
	
	if (argc != 2)
	{
		ft_putstr_fd("Error\n Make sure to have 2 arguments precisely.\n", 2);
		exit (EXIT_FAILURE);
	}
	fd = open (argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror ("Error\n");
		exit (EXIT_FAILURE);
	}
	file_to_tab(fd);
	close (fd);
	g()->mlx = mlx_init(512, 512, "so_long", false);
	if (!g()->mlx)
		error();
	i = 0;
	total = 0;
	numtex = 7;
	g()->img = ft_calloc(numtex + 1, sizeof (mlx_texture_t *));
	if (!g()->img)
	{
		ft_putstr_fd("Error\n Malloc Problem", 2);
		exit (EXIT_FAILURE);
	}
	g()->collect_count = 0;
	while (i < numtex)
	{
		texpath = ft_strdup(get_tex_path(i));
		if (!texpath)
		{
			ft_putstr_fd("Error\n Malloc Problem", 2);
			exit (EXIT_FAILURE);
		}
		tex = mlx_load_png(texpath);
		ft_free(texpath);
		if (!tex)
			error();
		g()->img[i] = mlx_texture_to_image(g()->mlx, tex);
		if (!g()->img[i])
			error();
		i++;
	}
	g()->move_px = 64;
	g()->lastkey = 'S';
	g()->char_layer = parse_img(g()->mlx, g()->img, g()->map);
	mlx_set_instance_depth(g()->img[3]->instances, g()->char_layer);
	mlx_key_hook(g()->mlx, &key_hooks, &total);
	mlx_loop(g()->mlx);
	mlx_terminate(g()->mlx);
	return (0);
}
