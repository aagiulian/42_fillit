/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:15:27 by mkantzer          #+#    #+#             */
/*   Updated: 2016/11/21 15:44:39 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	**tab;

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
	ft_test_stock(tab);
	return (0);
}
