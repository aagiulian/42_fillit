/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 10:18:59 by mkantzer          #+#    #+#             */
/*   Updated: 2016/11/18 18:01:35 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft.h"
# define BUF_SIZE 21

int		ft_check(char *file);
int		ft_check_size(char *buf);
int		ft_check_tetri(char *buf);
int		ft_check_grid(char *buf);

#endif
