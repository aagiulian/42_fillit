/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:47:18 by agiulian          #+#    #+#             */
/*   Updated: 2016/11/21 18:33:46 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_puttetri(char *tetri, char *grid, int pos, int r)
{
	int	j;
	int i;
	int	count;

	count = 0;
	j = 0;
	r += 1;
	i = pos;
	while (grid[pos])
	{
		if (grid[pos] == '.')
		{
			if (tetri[j] == i + 65)
			{
				grid[pos] = tetri[j];
				count++;
			}
			if (tetri[j] == '\n')
				pos +=  r - (pos % r);
			else
				pos++;
			j++;
		}
		else if (grid[pos] == '\n')
			pos++;
		else
			return (0);
	}
	if (count == 4)
		return (1);
	else
		return (0);
}

char	*ft_backtracking(char **tab, int pos, char *grid, int r)
{
	int		count;
	char	*save;
	int		flag;

	count = 0;
	flag = 0;
	save = grid;
	while (count != ft_tablen(tab))
	{
	while (flag)
	{
		grid = save;
		flag = ft_puttetri(tetri, pos + 1, grid, r);
	}
	return (grid)
}



