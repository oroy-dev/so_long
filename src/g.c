/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:57:28 by oroy              #+#    #+#             */
/*   Updated: 2023/08/16 15:58:47 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*g(void)
{
	static t_data	ptr;

	if (!ptr.move_px)
	{
		ptr.move_px = 64;
		ptr.numtex = 8;
		ptr.width = 0;
		ptr.height = 0;
		ptr.lastkey = 'S';
		ptr.collect_count = 0;
		ptr.collect_onscreen = 0;
	}
	return (&ptr);
}
