/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 14:59:18 by mkantzer          #+#    #+#             */
/*   Updated: 2016/11/24 14:55:34 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_endl(char *file)
{
	int		fd;
	int		i;
	int		ret;
	int		count;
	char	buf[4096];

	i = 0;
	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	if ((ret = read(fd, buf, 4096)))
		buf[ret] = '\0';
	while (buf[i])
	{
		if (buf[i] == '\n')
			count++;
		i++;
	}
	if ((count + 1) % 5 != 0)
		return (0);
	close(fd);
	return (1);
}

int		ft_check_size(char *buf)
{
	int	countn;
	int	countc;
	int	i;

	countn = 0;
	i = 0;
	while (buf[i])
	{
		countc = 0;
		while (buf[i] != '\n')
		{
			if (buf[i] != '.' && buf[i] != '#')
				return (0);
			countc++;
			i++;
		}
		if (countc != 4 && countn != 4)
			return (0);
		if (buf[i] != '\n')
			return (0);
		else
			countn++;
		i++;
	}
	return (1);
}

int		ft_check_grid(char *buf)
{
	int	i;
	int	point;
	int sharp;

	i = 0;
	point = 0;
	sharp = 0;
	while (buf[i])
	{
		if (buf[i] == '.')
			point = 1;
		if (buf[i] == '#')
			sharp = 1;
		i++;
	}
	if (point && sharp)
		return (1);
	else
		return (0);
}

int		ft_check_sharp(char *buf)
{
	int	i;
	int	sharp;

	i = 0;
	sharp = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
			sharp++;
		i++;
	}
	if (sharp != 4)
		return (0);
	return (1);
}

int		ft_check_tetri(char *buf)
{
	int i;
	int countc;

	i = 0;
	countc = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			if (buf[i + 1] == '#' && buf[i + 1])
				countc++;
			if (buf[i - 1] == '#' && buf[i - 1])
				countc++;
			if (buf[i + 5] == '#' && buf[i + 5])
				countc++;
			if (buf[i - 5] == '#' && buf[i - 5])
				countc++;
		}
		i++;
	}
	if (countc >= 6)
		return (1);
	else
		return (0);
}
