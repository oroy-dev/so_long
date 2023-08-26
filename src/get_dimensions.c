/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:43:28 by oroy              #+#    #+#             */
/*   Updated: 2023/08/19 18:05:00 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_height(void)
{
	g()->height *= g()->px;
	return (g()->height);
}

int	get_width(void)
{
	g()->width = ft_strlen(g()->map[0]) * g()->px;
	return (g()->width);
}
