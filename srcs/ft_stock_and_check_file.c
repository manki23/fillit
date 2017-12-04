/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_and_check_file.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:33:51 by manki             #+#    #+#             */
/*   Updated: 2017/12/04 17:50:19 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>

int				ft_nb_row(char *tab)
{
	int		i;
	int		row;

	row = 0;
	i = -1;
	while (tab[++i])
	{
		while (tab[i] != '\n')
			++i;
		++row;
	}
	return (row);
}

static t_bool	ft_check_number(char *tab)
{
	int		i;
	int		count;
	int		row;

	i = -1;
	count = 0;
	row = 0;
	while (tab[++i])
	{
		while (tab[i] != '\n')
		{
			if (tab[i] == '#')
				++count;
			++i;
		}
		++row;
		if (((row % 5) == 0 && tab[i - 1] == '\n') || row == ft_nb_row(tab))
		{
			if (count != 4)
				return (0);
			count = 0;
		}
	}
	return (1);
}

static t_bool	ft_check_norme(char *tab)
{
	int			i;
	t_coord		c;

	i = -1;
	c.y = 0;
	while (tab[++i])
	{
		c.x = 0;
		while (tab[i] != '\n')
		{
			if (tab[i] != '.' && tab[i] != '#')
				return (0);
			c.x++;
			++i;
		}
		c.y++;
		if ((c.y % 5 == 0 && tab[i - 1] != '\n')
			|| (tab[i] == '\n' && tab[i - 1] == '\n' && tab[i + 1] == '\n')
			|| (c.x != 4 && c.x != 0) || !(ft_check_number(tab)))
			return (0);
		else if (tab[i - 1] != '\n' && tab[i] == '\n' && tab[i + 1] == '\0')
			return (1);
	}
	return (0);
}

static char		*ft_writetab(char *file, char *tab)
{
	int		fd;
	char	buf;
	int		i;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	i = 0;
	while (read(fd, &buf, 1) > 0)
		tab[i++] = buf;
	close(fd);
	return (tab);
}

char			*ft_checkfile(char *file)
{
	int		fd;
	char	buf;
	char	*tab;
	int		len;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	len = 0;
	while (read(fd, &buf, 1) > 0)
		len++;
	if (!(tab = ft_memalloc(len + 1)))
		return (NULL);
	if (!(tab = ft_writetab(file, tab)))
		return (NULL);
	if (!ft_check_norme(tab) || ((ft_nb_row(tab) + 1) % 5))
		return (NULL);
	close(fd);
	return (tab);
}
