/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 03:12:05 by agiulian          #+#    #+#             */
/*   Updated: 2016/11/23 18:24:38 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_xtrm	*init_struct(int x, int y)
{
	t_xtrm	*xtrm;

	if (!(xtrm = malloc(sizeof(t_xtrm))))
		return (NULL);
	xtrm->min = x;
	xtrm->max = y;
	return (xtrm);
}

void	get_xy_min_max(t_xtrm *x, t_xtrm *y, char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			if (i % 5 < x->min)
				x->min = i % 5;
			if (i % 5 > x->max)
				x->max = i % 5;
			if (i / 5 < y->min)
				y->min = i / 5;
			if (i / 5 > y->max)
				y->max = i / 5;
		}
		i++;
	}
}

char	*get_tetri(char *buf, t_xtrm *x, t_xtrm *y)
{
	char	*tetri;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(tetri = (char*)malloc(sizeof(char) * (((y->max - y->min + 1) \
		* (x->max - x->min + 1)) + (y->max - y->min + 1) + 1))))
		return (NULL);
	while (i < 21)
	{
		while ((i / 5) >= y->min && (i / 5) <= y->max)
		{
			if (((i % 5) >= x->min && (i % 5) <= x->max) || (buf[i] == '\n'))
			{
				tetri[j] = buf[i];
				j++;
			}
			i++;
		}
		i++;
	}
	tetri[j] = '\0';
	return (tetri);
}

char	*to_letter(char *s, int i)
{
	int	j;

	j = 0;
	while (s[j])
	{
		if (s[j] == '#')
			s[j] = 65 + i;
		j++;
	}
	return (s);
}

char	**store_tetris(int i, char *buf, char **tab)
{
	t_xtrm	*x;
	t_xtrm	*y;
	int		j;

	j = 0;
	x = init_struct(3, 0);
	y = init_struct(3, 0);
	get_xy_min_max(x, y, buf);
	tab[i] = to_letter(get_tetri(buf, x, y), i);
	i++;
	tab[i] = NULL;
	return (tab);
}
