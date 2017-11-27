/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:34:46 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/26 10:13:01 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef int		t_bool;

char			*ft_stock_and_check_file(char *file);

int				**ft_split_rec_tetri(char *tab);

int				ft_nb_tetri(char *tab);
int				ft_nb_row(char *tab);
int				ft_sqrt(int nb);

t_bool			ft_solve_grid(int **id, char *tab, int len, char **grid);

#endif
