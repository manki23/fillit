/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:00:21 by manki             #+#    #+#             */
/*   Updated: 2017/12/04 18:56:26 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <stdlib.h>

static int		ft_error(void)
{
	ft_putstr("error\n");
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
			return (ft_error());
		if (!(tetris = ft_record_tetris(tab)))
			return (ft_error());
		ft_resolve_grid(tetris);
		ft_free_tetris(tetris);
	}
	else if (ac < 1)
		write(2, "File name missing.\n", 19);
	else
		write(2, "Too many arguments.\n", 20);
	return (0);
}
