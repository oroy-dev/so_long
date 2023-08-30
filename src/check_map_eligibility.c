/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_eligibility.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:09:46 by oroy              #+#    #+#             */
/*   Updated: 2023/08/30 15:24:53 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map_items(void)
{
	if (!td()->player_on)
		print_error("Error\nNo player found");
	else if (!td()->collectotal)
		print_error("Error\nNo collectible found");
	else if (!td()->exit_on)
		print_error("Error\nNo exit found");
}

static void	check_map_char(char c, int row, int col)
{
	if (row == 0 || (row == td()->height - 1 && col <= td()->width - 2)
		|| col == 0 || col == td()->width - 2)
	{
		if (c != '1')
			print_error("Error\nMap not closed");
	}
	else if (col > td()->width - 2)
		print_error("Error\nMap not rectangular");
	else if (c == 'P')
	{
		if (td()->player_on)
			print_error("Error\nOnly one player (P) required");
		td()->x = col;
		td()->y = row;
		td()->player_on = 1;
	}
	else if (c == 'C')
		td()->collectotal++;
	else if (c == 'E')
	{
		if (td()->exit_on)
			print_error("Error\nOnly one exit (E) required");
		td()->exit_on = 1;
	}
}

void	check_map_eligibility(char **map)
{
	int		row;
	int		col;

	if (!map)
		print_error("Error\nEmpty map");
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (!ft_strchr("01CEP", map[row][col]))
				print_error("Error\nCharacter not valid");
			check_map_char(map[row][col], row, col);
			col++;
		}
		if (col != td()->width - 1)
			print_error("Error\nMap not rectangular");
		row++;
	}
	check_map_items();
	flood_fill();
}
