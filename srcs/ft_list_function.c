/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:44:12 by manki             #+#    #+#             */
/*   Updated: 2017/12/02 14:12:34 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

t_tetris	*ft_create_elem(int *content)
{
	t_tetris	*elem;
	int			*copy;

	elem = (t_tetris *)ft_memalloc(sizeof(t_tetris));
	if (elem)
	{
		copy = content;
		elem->id = copy;
		elem->next = NULL;
		content = NULL;
	}
	return (elem);
}

void		ft_push_back(t_tetris **tetris, int *content)
{
	t_tetris	*tmp;

	if (tetris)
	{
		tmp = *tetris;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_elem(content);
	}
}

void		ft_print_tetris(t_tetris *tetris)
{
	t_tetris	*tmp;
	int			*id;
	int			i;

	if (tetris)
	{
		tmp = tetris;
		while (tmp)
		{
			i = -1;
			if (!(id = tmp->id))
				return ;
			ft_putchar('|');
			while (++i < 4)
			{
				ft_putnbr(id[i]);
				ft_putchar('|');
			}
			ft_putchar('\n');
			tmp = tmp->next;
		}
	}
}

t_tetris	*ft_free_tetris(t_tetris *tetris)
{
	t_tetris	*tmp;

	if (tetris)
	{
		while (tetris)
		{
			tmp = tetris;
			tetris = tetris->next;
			free(tmp->id);
			tmp->id = NULL;
			free(tmp);
			tmp = NULL;
		}
	}
	return (tetris);
}

int			ft_nb_tetris(t_tetris *tetris)
{
	t_tetris	*tmp;
	int			len;

	len = 0;
	if (tetris)
	{
		tmp = tetris;
		while (tmp)
		{
			tmp = tmp->next;
			len++;
		}
	}
	return (len);
}
