/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:14:17 by oroy              #+#    #+#             */
/*   Updated: 2023/08/16 16:15:04 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	malloc_check(void *maloc)
{
	if (!maloc)
	{
		ft_putendl_fd("Malloc Error", 2);
		// close_all();
		// free_data();
		exit (EXIT_FAILURE);
	}
}
