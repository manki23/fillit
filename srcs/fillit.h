/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:03:00 by manki             #+#    #+#             */
/*   Updated: 2017/12/04 18:18:51 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

typedef int		t_bool;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_tetris
{
	int					*id;
	struct s_tetris		*next;
}				t_tetris;

int				ft_sqrt(int nb);

char			*ft_checkfile(char *file);
int				ft_nb_row(char *tab);

t_tetris		*ft_create_elem(int *content);
void			ft_push_back(t_tetris **tetris, int *content);
void			ft_print_tetris(t_tetris *tetris);
t_tetris		*ft_free_tetris(t_tetris *tetris);
int				ft_nb_tetris(t_tetris *tetris);

t_tetris		*ft_record_tetris(char *tab);

char			**ft_resolve_grid(t_tetris *tetris);
void			ft_print_result(char **grid, int len);
t_bool			ft_recursive(t_tetris *tetris, char **grid, int l, t_coord *g);

#endif
