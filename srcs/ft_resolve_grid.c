/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 13:50:30 by manki             #+#    #+#             */
/*   Updated: 2017/12/04 18:42:19 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static char		**ft_create_square(int len)
{
	char	**square;
	int		i;

	if (!(square = (char **)malloc(sizeof(char *) * len)))
		return (NULL);
	i = -1;
	while (++i < len)
	{
		if (!(square[i] = (char *)malloc(sizeof(char) * len)))
			return (NULL);
		ft_memset(square[i], '.', len);
	}
	return (square);
}

void			ft_print_result(char **grid, int len)
{
	t_coord		c;

	c.y = -1;
	while (++c.y < len)
	{
		c.x = -1;
		while (++c.x < len)
			ft_putchar(grid[c.y][c.x]);
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
	while (ft_recursive(tetris, grid, len, &g) != 1)
	{
		ft_free_grid(grid, len);
		len++;
		if (!(grid = ft_create_square(len)))
			return (NULL);
	}
	ft_print_result(grid, len);
	grid = ft_free_grid(grid, len);
	return (NULL);
}
