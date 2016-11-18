/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 14:59:18 by mkantzer          #+#    #+#             */
/*   Updated: 2016/11/18 17:55:32 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check(char *file)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		ft_putstr("New Tetro\n");
		buf[ret] = '\0';
		if (!ft_check_size(buf))
			return (0);
		if (!ft_check_grid(buf))
			return (0);
		if (!ft_check_tetro(buf))
			return (0);
	}
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

int		ft_check_tetro(char *buf)
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
