/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 10:18:59 by mkantzer          #+#    #+#             */
/*   Updated: 2016/11/23 19:00:51 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft.h"
# define BUF_SIZE 21

typedef struct	s_xtrm
{
	int			min;
	int			max;
}				t_xtrm;

void			ft_print_tab(char **tab);
char			**store_tetris(int i, char *buf, char **tab);
char			*get_tetri(char *buf, t_xtrm *x, t_xtrm *y);
char			**ft_check(char *file);
int				ft_check_size(char *buf);
int				ft_check_tetri(char *buf);
int				ft_check_sharp(char *buf);
int				ft_check_grid(char *buf);
int				ft_puttetri(char *tetri, char **grid, int pos, int letter);
int				ft_endl(char *file);
int				ft_backtracking(char **tab, int pos, char **grid, int letter);
int				ft_get_width(char *tetri);
void			ft_deltetri(char **grid, int letter);
char			*ft_solve(char **tab, char **grid);
char			**ft_grid_creation(int grid_min);
int				ft_grid_min(char **tab);

#endif
