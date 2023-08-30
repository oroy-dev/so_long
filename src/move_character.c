/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:31:40 by oroy              #+#    #+#             */
/*   Updated: 2023/08/30 16:07:11 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_for_item_hit(void)
{
	int	i;

	i = 0;
	if (td()->map[td()->y][td()->x] == 'C')
	{
		while (i < td()->collectotal)
		{
			if (ti()->light_l->instances[i].x == td()->x * td()->px
				&& ti()->light_r->instances[i].y == td()->y * td()->px)
			{
				ti()->light_l->instances[i].z = -1;
				ti()->light_r->instances[i].z = -1;
				td()->map[td()->y][td()->x] = '0';
				td()->collect--;
				break ;
			}
			i++;
		}
	}
	else if (td()->map[td()->y][td()->x] == 'E' && !td()->collect)
	{
		ft_printf ("You won!");
		mlx_close_window(td()->mlx);
	}
}

static void	update_pos(mlx_image_t *character)
{
	character->instances[0].x = td()->x * td()->px;
	character->instances[0].y = td()->y * td()->px;
	if (td()->currentdir != character)
	{
		td()->currentdir->instances[0].enabled = false;
		character->instances[0].enabled = true;
		td()->currentdir = character;
	}
}

static mlx_image_t	*get_character_dir(char key)
{
	if (key == 'W')
		return (ti()->train_b);
	else if (key == 'D')
		return (ti()->train_r);
	else if (key == 'A')
		return (ti()->train_l);
	else
		return (ti()->train_f);
}

void	move_character(char key)
{
	update_pos(get_character_dir(key));
	check_for_item_hit();
}
