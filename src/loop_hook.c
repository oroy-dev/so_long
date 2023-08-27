/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:04:45 by oroy              #+#    #+#             */
/*   Updated: 2023/08/26 20:05:32 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	change_light_state(mlx_image_t *img1, mlx_image_t *img2)
{
	int	i;

	i = 0;
	while (i < td()->collect_count)
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
		change_light_state(ti()->light_l, ti()->light_r);
	else if ((int)mlx_get_time() % 2 == 0)
		change_light_state(ti()->light_r, ti()->light_l);
}
