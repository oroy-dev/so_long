/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:24:55 by oroy              #+#    #+#             */
/*   Updated: 2024/12/09 19:21:28 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_error_check(void *ptr)
{
	if (!ptr)
	{
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), 2);
		mlx_terminate(td()->mlx);
		ft_free_tab(td()->map);
		exit (EXIT_FAILURE);
	}
}

void	print_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	ft_free_tab(td()->map);
	exit (EXIT_FAILURE);
}
