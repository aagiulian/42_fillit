/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:47:18 by agiulian          #+#    #+#             */
/*   Updated: 2016/11/24 14:53:03 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_puttetri(char *tetri, char **grid, int pos, int letter)
{
	int clwc[4];

	clwc[0] = pos % ft_strlen(grid[0]);
	clwc[1] = pos / ft_strlen(grid[0]);
	clwc[2] = ft_get_width(tetri);
	clwc[3] = 0;
	while (clwc[1] < (int)ft_strlen(grid[0]) && *tetri)
	{
		if (clwc[3] == 4)
			return (1);
		if (*tetri == '\n')
		{
			clwc[1]++;
			clwc[0] = clwc[0] - clwc[2] - 1;
		}
		else if (*tetri == letter + 65 && grid[clwc[1]][clwc[0]] == '.')
		{
			grid[clwc[1]][clwc[0]] = *tetri;
			clwc[3]++;
		}
		clwc[0]++;
		tetri++;
	}
	ft_deltetri(grid, letter);
	return (0);
}

int		ft_get_width(char *tetri)
{
	int i;

	i = 0;
	while (tetri[i] != '\n')
		i++;
	return (i);
}

void	ft_deltetri(char **grid, int letter)
{
	int i;
	int j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == letter + 65)
				grid[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		ft_backtracking(char **tab, int pos, char **grid, int letter)
{
	int max;

	max = ft_strlen(grid[0]) * ft_strlen(grid[0]);
	if (*tab == NULL)
	{
		ft_print_tab(grid);
		exit(0);
	}
	if (pos >= max - 1)
	{
		return (1);
	}
	if (ft_puttetri(*tab, grid, pos, letter))
	{
		ft_backtracking(tab + 1, 0, grid, (letter + 1));
		ft_deltetri(grid, letter);
	}
	ft_backtracking(tab, (pos + 1), grid, letter);
	return (0);
}
