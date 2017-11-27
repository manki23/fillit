/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 09:54:14 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/15 17:49:07 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_calc_neg(char *nbr, int n, int i)
{
	int nb;
	int j;

	j = 0;
	nbr[0] = '-';
	--i;
	while (i > j)
	{
		nb = n;
		nbr[i] = -(nb % 10) + '0';
		n /= 10;
		--i;
	}
	return (nbr);
}

static char	*ft_calc_pos(char *nbr, int n, int i)
{
	int nb;
	int j;

	j = 0;
	--i;
	while (i >= j)
	{
		nb = n;
		nbr[i] = (nb % 10) + '0';
		n /= 10;
		--i;
	}
	return (nbr);
}

char		*ft_itoa(int n)
{
	int		nb;
	int		i;
	char	*nbr;

	nb = n;
	i = 0;
	n == 0 ? i = 1 : i;
	while (nb != 0)
	{
		nb /= 10;
		++i;
	}
	n < 0 ? ++i : i;
	if (!(nbr = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (n < 0)
		ft_calc_neg(nbr, n, i);
	else
		ft_calc_pos(nbr, n, i);
	nbr[i] = '\0';
	return (nbr);
}
