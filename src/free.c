/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:19:56 by olivierroy        #+#    #+#             */
/*   Updated: 2024/12/09 19:20:16 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(void *ptr)
{
	if (ptr)
	{
		free (ptr);
		ptr = NULL;
	}
}

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free (tab[i]);
			i++;
		}
		ft_free(tab);
	}
}
