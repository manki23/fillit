/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_norme.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:46:25 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/26 09:57:46 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

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
			else
				count = 0;
		}
	}
	return (1);
}

static t_bool	ft_check_norme(char *tab)
{
	int		i;
	int		col;
	int		row;

	i = -1;
	row = 0;
	while (tab[++i])
	{
		col = 0;
		while (tab[i] != '\n')
		{
			if (tab[i] != '.' && tab[i] != '#')
				return (0);
			col++;
			++i;
		}
		row++;
		if ((row % 5 == 0 && tab[i - 1] != '\n')
			|| (tab[i] == '\n' && tab[i - 1] == '\n' && tab[i + 1] == '\n')
			|| (col != 4 && col != 0) || !(ft_check_number(tab)))
			return (0);
		else if (tab[i - 1] != '\n' && tab[i] == '\n' && tab[i + 1] == '\0')
			return (1);
	}
	return (0);
}

static char		*ft_write(char *file, char *tab)
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

char			*ft_stock_and_check_file(char *file)
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
	if (!(tab = ft_write(file, tab)))
		return (NULL);
	if (!ft_check_norme(tab))
		return (NULL);
	close(fd);
	return (tab);
}
