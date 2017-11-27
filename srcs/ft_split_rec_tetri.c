/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:07:29 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/26 10:22:17 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"
#include <stdlib.h>

static int		ft_check_one(char *tab)
{
	int		i;
	int		count;

	i = 0;
	count = 1;
	while (tab[i])
	{
		if (tab[i] == '#' && count < 4)
		{
			if (tab[i + 1] == '#' && tab[i + 2] == '#' && tab[i + 5] == '#')
				return (1);
			if (tab[i + 1] != '#' && tab[i + 3] != '#'
					&& tab[i + 4] != '#' && tab[i + 5] != '#')
				return (0);
			++count;
			if (tab[i + 1] != '#' && tab[i + 4] != '#'
					&& tab[i + 5] != '#')
				return (0);
		}
		++i;
	}
	return (1);
}

static void		ft_split(char *tab, char **group, int len)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	while (++i < len)
	{
		if (!(group[i] = (char *)malloc(sizeof(char) * 21)))
			return ;
		j = -1;
		while (++j < 20)
		{
			group[i][j] = tab[k];
			++k;
		}
		group[i][j] = '\0';
		++k;
	}
	group[i] = 0;
}

static char		**ft_split_tetri(char *tab)
{
	char	**group;
	int		len;
	int		i;

	if ((len = ft_nb_tetri(tab)) > 26)
		return (0);
	if (!(group = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	ft_split(tab, group, len);
	i = -1;
	while (group[++i])
		if (!ft_check_one(group[i]))
			return (NULL);
	return (group);
}

static void		ft_id_one_tetri(char *tab, int *id, int index)
{
	int		i;
	int		q;
	int		count;

	i = -1;
	count = 1;
	id[0] = index;
	while (tab[++i] && count < 4)
	{
		q = 1;
		while (tab[i] == '#' && tab[i + q] != '#')
			q++;
		if (tab[i] == '#')
		{
			id[count] = q;
			count++;
		}
	}
}

int				**ft_split_rec_tetri(char *tab)
{
	char	**group;
	int		**id;
	int		i;
	int		len;

	len = ft_nb_tetri(tab);
	if (!(id = (int **)malloc(sizeof(int *) * len)))
		return (NULL);
	if (!(group = ft_split_tetri(tab)))
		return (NULL);
	i = -1;
	while (++i < len)
		if (!(id[i] = (int *)malloc(sizeof(int) * 4)))
			return (NULL);
	i = -1;
	while (++i < len)
		ft_id_one_tetri(group[i], id[i], i);
	free(group);
	return (id);
}
