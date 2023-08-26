/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_eligibility.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:09:46 by oroy              #+#    #+#             */
/*   Updated: 2023/08/25 22:26:52 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map_items(void)
{
	if (!g()->player_on)
		print_err("Error\nNo player found");
	else if (!g()->collect_count)
		print_err("Error\nNo collectible found");
	else if (!g()->exit_on)
		print_err("Error\nNo exit found");
}

static void	check_map_char(char c, int row, int col)
{
	if (row == 0 || (row == g()->height - 1 && col <= g()->width - 2)
		|| col == 0 || col == g()->width - 2)
	{
		if (c != '1')
			print_err("Error\nMap not closed");
	}
	else if (col > g()->width - 2)
		print_err("Error\nMap not rectangular");
	else if (c == 'P')
	{
		if (g()->player_on)
			print_err("Error\nOnly one player (P) required");
		g()->x = col;
		g()->y = row;
		g()->player_on = 1;
	}
	else if (c == 'C')
		g()->collect_count++;
	else if (c == 'E')
	{
		if (g()->exit_on)
			print_err("Error\nOnly one exit (E) required");
		g()->exit_on = 1;		
	}
}

void	check_map_eligibility(char **map)
{
	int		row;
	int		col;

	if (!map)
		print_err("Error\nEmpty map");
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (!ft_strchr("01CEP", map[row][col]))
				print_err("Error\nCharacter not valid");
			check_map_char(map[row][col], row, col);
			col++;
		}
		if (col != g()->width - 1)
			print_err("Error\nMap not rectangular");
		row++;
	}
	check_map_items();
	flood_fill();
}
