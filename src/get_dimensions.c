/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:43:28 by oroy              #+#    #+#             */
/*   Updated: 2023/08/26 21:51:25 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_height(void)
{
	td()->height *= td()->px;
	return (td()->height);
}

int	get_width(void)
{
	td()->width = (td()->width - 1) * td()->px;
	return (td()->width);
}
