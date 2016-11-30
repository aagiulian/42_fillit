/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:15:27 by mkantzer          #+#    #+#             */
/*   Updated: 2016/11/24 15:42:54 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

char	**ft_check(char *file)
{
	int		fd;
	int		i;
	int		ret;
	char	**tab;
	char	buf[BUF_SIZE + 1];

	i = 0;
	tab = (char**)ft_memalloc(27 * sizeof(char*));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((!ft_check_size(buf)) || (!ft_check_grid(buf)) || \
				(!ft_check_sharp(buf)) || !ft_check_tetri(buf))
			return (NULL);
		if ((!ft_endl(file)) || (!store_tetris(i, buf, tab)))
			return (0);
		i++;
	}
	if (tab[0] == NULL)
		return (0);
	close(fd);
	return (tab);
}

int		main(int argc, char **argv)
{
	char	**tab;
	char	**grid;
	int		grid_min;
	int		i;

	i = 0;
	if (argc != 2)
	{
		ft_putstr("usage: fillit {tetriminos_entry_file}\n");
		return (0);
	}
	if (!(tab = ft_check(argv[1])))
	{
		ft_putstr("error\n");
		return (0);
	}
	grid_min = ft_grid_min(tab);
	grid = ft_grid_creation(grid_min);
	while (!ft_backtracking(tab, 0, grid, 0))
	{
		free(grid);
		grid = ft_grid_creation(++grid_min);
	}
	return (0);
}
