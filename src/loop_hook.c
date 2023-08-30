/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:04:45 by oroy              #+#    #+#             */
/*   Updated: 2023/08/30 15:41:13 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	change_light_state(mlx_image_t *img1, mlx_image_t *img2, int total)
{
	int	i;

	i = 0;
	while (i < total)
	{
		img1->instances[i].enabled = true;
		img2->instances[i].enabled = false;
		i++;
	}
}

void	loop_hook(void *param)
{
	(void) param;
	if ((int)mlx_get_time() % 2 == 1)
	{
		if (td()->collect)
			change_light_state(ti()->light_l, ti()->light_r, td()->collectotal);
		else
			change_light_state(ti()->station_off, ti()->station_on, 1);
	}
	else if ((int)mlx_get_time() % 2 == 0)
	{
		if (td()->collect)
			change_light_state(ti()->light_r, ti()->light_l, td()->collectotal);
		else
			change_light_state(ti()->station_on, ti()->station_off, 1);
	}
}
