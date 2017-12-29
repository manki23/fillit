/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 13:50:30 by manki             #+#    #+#             */
/*   Updated: 2017/12/23 15:06:07 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static char		**ft_create_square(int len)
{
	char	**square;
	int		i;

	if (!(square = (char **)ft_memalloc(sizeof(char *) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
	{
		if (!(square[i] = ft_strnew(len)))
			return (NULL);
		ft_memset(square[i], '.', len);
		square[i][len] = '\0';
	}
	square[i] = 0;
	return (square);
}

void			ft_print_result(char **grid, int len)
{
	t_coord		c;

	c.y = -1;
	while (++c.y < len)
	{
		ft_putstr(grid[c.y]);
		ft_putchar('\n');
	}
}

static char		**ft_free_grid(char **grid, int len)
{
	int		i;

	i = -1;
	while (++i < len)
	{
		free(grid[i]);
		grid[i] = NULL;
	}
	free(grid);
	grid = NULL;
	return (grid);
}

char			**ft_resolve_grid(t_tetris *tetris)
{
	char	**grid;
	int		len;
	t_coord	g;

	len = ft_sqrt(ft_nb_tetris(tetris) * 4);
	if (!(grid = ft_create_square(len)))
		return (NULL);
	g.x = 0;
	g.y = 0;
	while (!ft_recursive(tetris, grid, len, &g))
	{
		ft_free_grid(grid, len);
		++len;
		g.x = 0;
		g.y = 0;
		if (!(grid = ft_create_square(len)))
			return (NULL);
	}
	ft_print_result(grid, len);
	grid = ft_free_grid(grid, len);
	return (NULL);
}
