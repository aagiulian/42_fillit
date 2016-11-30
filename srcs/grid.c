/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:57:02 by mkantzer          #+#    #+#             */
/*   Updated: 2016/11/23 17:08:36 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_fill_grid(char **grid, int min)
{
	int	i;
	int j;

	i = 0;
	while (i < min)
	{
		j = 0;
		while (j < min)
		{
			grid[i][j] = '.';
			j++;
		}
		grid[i][j] = '\0';
		i++;
	}
	grid[i] = NULL;
}

char	**ft_grid_creation(int min)
{
	int		i;
	char	**grid;

	i = 0;
	if (!(grid = (char**)malloc(((min + 1) * sizeof(char*)))))
		return (NULL);
	while (i < min)
	{
		if (!(grid[i] = ((char*)malloc(sizeof(char) * min + 1))))
			return (NULL);
		i++;
	}
	grid[i] = NULL;
	ft_fill_grid(grid, min);
	return (grid);
}

int		ft_grid_min(char **tab)
{
	int r;
	int i;

	i = 0;
	r = 0;
	while (tab[i])
		i++;
	while ((r * r) < (i * 4))
		r++;
	return (r);
}
