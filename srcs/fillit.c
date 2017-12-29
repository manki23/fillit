/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:00:21 by manki             #+#    #+#             */
/*   Updated: 2017/12/29 16:21:29 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <stdlib.h>

static int		ft_error(char *str, int fd)
{
	ft_putendl_fd(str, fd);
	return (-1);
}

int				main(int ac, char **av)
{
	char		*tab;
	t_tetris	*tetris;

	ac--;
	av++;
	if (ac == 1)
	{
		if (!(tab = ft_checkfile(av[0])))
			return (ft_error("error", 1));
		if (!(tetris = ft_record_tetris(tab)))
			return (ft_error("error", 1));
		ft_resolve_grid(tetris);
		ft_free_tetris(tetris);
	}
	else
		ft_putendl_fd("usage: ./fillit [file_name]", 2);
	return (0);
}
