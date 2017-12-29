/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_record_tetris.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 10:37:08 by manki             #+#    #+#             */
/*   Updated: 2017/12/27 16:23:50 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static t_bool	ft_check_one(int *id)
{
	int			i;
	int			c;
	int			ok;

	c = (id[1] * 100) + (id[2] * 10) + id[3];
	if (c == 131 || c == 113 || c == 311 || c == 141 || c == 114 || c == 411)
		return (1);
	i = 0;
	ok = 1;
	while (++i < 4)
		if (id[i] != 1 && id[i] != 5)
			ok = 0;
	if (c == 414 || c == 541 || c == 145 || c == 514 || c == 415)
		ok = 1;
	return (ok);
}

static t_bool	ft_check_tetris(t_tetris *tetris)
{
	t_tetris	*tmp;
	int			*id;
	int			i;

	i = 0;
	if (tetris)
	{
		tmp = tetris;
		while (tmp)
		{
			id = tmp->id;
			if (!ft_check_one(id))
				return (0);
			tmp = tmp->next;
			++i;
		}
	}
	if (i > 26)
		return (0);
	return (1);
}

static int		*ft_id(int index, int *pos, char *tab)
{
	int		q;
	int		*id;
	int		count;

	if (!(id = (int *)ft_memalloc(sizeof(int) * 4)))
		return (NULL);
	id[0] = index;
	count = 1;
	while (tab[*pos] && count < 4)
	{
		q = 1;
		while (tab[*pos] == '#' && tab[*pos + q] != '#')
			q++;
		if (tab[*pos] == '#')
		{
			id[count] = q;
			count++;
		}
		*pos += 1;
	}
	*pos += q;
	return (id);
}

t_tetris		*ft_record_tetris(char *tab)
{
	t_tetris	*tetris;
	int			i;
	int			index;
	int			*id;

	i = -1;
	index = 0;
	while (tab[++i])
	{
		if (tab[i] == '#')
		{
			if (!(id = ft_id(index, &i, tab)))
				return (NULL);
			if (index == 0)
				tetris = ft_create_elem(id);
			else
				ft_push_back(&tetris, id);
			index++;
		}
	}
	if (!ft_check_tetris(tetris))
		tetris = ft_free_tetris(tetris);
	free(tab);
	return (tetris);
}
