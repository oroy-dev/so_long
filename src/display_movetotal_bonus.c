/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_movetotal_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:59:39 by oroy              #+#    #+#             */
/*   Updated: 2023/08/31 16:04:44 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	malloc_check(void *ptr)
{
	if (!ptr)
	{
		mlx_terminate(td()->mlx);
		print_error("Error\nMalloc failed");
	}
}

void	display_movetotal_bonus(int px)
{
	mlx_image_t	*text;
	char		*count;
	char		*str;

	count = ft_itoa(td()->movetotal);
	malloc_check(count);
	str = ft_strjoin("Move Total: ", count);
	ft_free(count);
	malloc_check(str);
	if (td()->text)
		mlx_delete_image(td()->mlx, td()->text);
	text = mlx_put_string(td()->mlx, str, px / 2, td()->height + px / 2);
	td()->text = text;
	ft_free(str);
}
