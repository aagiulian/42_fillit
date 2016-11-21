/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:57:02 by mkantzer          #+#    #+#             */
/*   Updated: 2016/11/21 17:14:35 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_grid_creation(int min)
{
	int i;
	int j;
	char *grid;

	i = 0;
	j = 0;
	grid = (char*)malloc(((min * min) + min + 1) * sizeof(char));
	if (!grid)
		return (0);
	while (j < ((min * min) + min))
	{
		i = 0;
		while (i < min)
		{
			grid[j] = '.';
			i++;
			j++;
		}
		grid[j] = '\n';
		j++;
	}
	grid[j] = '\0';
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

int		ft_test_stock(char **tab)
{
	char	*grid;
	int		grid_min;
	int		i;

	i = 0;
	grid_min = ft_grid_min(tab);
	while (i <  3)
	{
		grid = ft_grid_creation(grid_min + i);
		ft_puttetri(tab[i], grid, i, grid_min + i);
		ft_putstr(grid);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
