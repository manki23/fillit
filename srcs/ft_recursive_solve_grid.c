/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_solve_grid.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:49:09 by manki             #+#    #+#             */
/*   Updated: 2017/12/29 12:39:15 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static t_bool	ft_increment_g(t_coord *g, int len)
{
	if (g->y + 1 <= len)
	{
		if (g->x + 1 < len)
			g->x++;
		else
		{
			g->x = 0;
			g->y++;
		}
		return (1);
	}
	else
		return (0);
}

static void		ft_remove_last(char **grid, int len, int index, t_coord *g)
{
	int		i;

	i = 0;
	g->y = len - 1;
	while (i < 4 && g->y >= 0)
	{
		g->x = len - 1;
		while (i < 4 && g->x >= 0)
		{
			if (grid[g->y][g->x] == 'A' + index)
			{
				grid[g->y][g->x] = '.';
				i++;
			}
			g->x--;
		}
		g->y--;
	}
	g->y++;
	g->x++;
	ft_increment_g(g, len);
}

static void		ft_decrypt(t_coord *c, t_coord *g, int *id)
{
	int		i;

	c[0].x = g->x;
	c[0].y = g->y;
	i = 0;
	while (++i < 4)
	{
		c[i].x = c[i - 1].x;
		c[i].y = c[i - 1].y;
		if (id[i] == 1)
			c[i].x += 1;
		else if (id[i] == 3)
		{
			c[i].x -= 2;
			c[i].y += 1;
		}
		else if (id[i] == 4)
		{
			c[i].x -= 1;
			c[i].y += 1;
		}
		else if (id[i] == 5)
			c[i].y += 1;
	}
}

t_bool			ft_fill_one(t_tetris *tetris, char **grid, int l, t_coord *g)
{
	t_coord		*c;
	int			i;
	int			*id;

	if (!(c = (t_coord *)ft_memalloc(sizeof(t_coord) * 4)))
		return (0);
	id = tetris->id;
	ft_decrypt(c, g, id);
	i = -1;
	while (++i < 4)
	{
		if (c[i].x >= l || c[i].y >= l || c[i].x < 0 || c[i].y < 0
				|| grid[c[i].y][c[i].x] != '.')
		{
			free(c);
			return (0);
		}
	}
	id = tetris->id;
	i = -1;
	while (++i < 4)
		grid[c[i].y][c[i].x] = id[0] + 'A';
	free(c);
	return (1);
}

t_bool			ft_recursive(t_tetris *tetris, char **grid, int len, t_coord *g)
{
	int		*id;

	if (!tetris)
		return (1);
	if ((g->x >= len) || (g->y >= len))
		return (0);
	if (ft_fill_one(tetris, grid, len, g))
	{
		g->x = 0;
		g->y = 0;
		if (ft_recursive(tetris->next, grid, len, g))
			return (1);
		else
		{
			id = tetris->id;
			ft_remove_last(grid, len, id[0], g);
			return (ft_recursive(tetris, grid, len, g));
		}
	}
	else
	{
		if (!ft_increment_g(g, len))
			return (0);
		return (ft_recursive(tetris, grid, len, g));
	}
}
