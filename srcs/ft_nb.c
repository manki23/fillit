/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:49:24 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/26 09:32:14 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

int		ft_sqrt(int nb)
{
	int i;

	i = 0;
	while (i <= 46340 && (i * i) < nb)
		++i;
	return (i);
}

int		ft_nb_row(char *tab)
{
	int	i;
	int	row;

	i = -1;
	row = 0;
	while (tab[++i])
	{
		while (tab[i] != '\n')
			++i;
		++row;
	}
	return (row);
}

int		ft_nb_tetri(char *tab)
{
	int	i;
	int	row;

	i = -1;
	row = 0;
	while (tab[++i])
	{
		while (tab[i] != '\n')
			++i;
		++row;
	}
	return ((row + 1) / 5);
}
