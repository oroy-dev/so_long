/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:04:45 by oroy              #+#    #+#             */
/*   Updated: 2023/08/23 18:06:19 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	change_light_state(int j, int k)
{
	int	i;

	i = 0;
	while (i < g()->collect_count)
	{
		g()->img[j]->instances[i].enabled = true;
		g()->img[k]->instances[i].enabled = false;
		i++;
	}
}

void	loop_hook(void* param)
{
	(void) param;
	if ((int)mlx_get_time() % 2 == 1)
		change_light_state(10, 11);
	else if ((int)mlx_get_time() % 2 == 0)
		change_light_state(11, 10);
}
