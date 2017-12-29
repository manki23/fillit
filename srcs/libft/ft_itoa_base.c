/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 10:52:48 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/26 09:43:55 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_nb(int value, int base)
{
	int len;

	if (value == 0)
		return (1);
	len = (value < 0 && base == 10) ? 1 : 0;
	while (value)
	{
		value /= base;
		++len;
	}
	return (len);
}

static void	ft_calc(char *nbr, int value, int base, int len)
{
	int	stop;

	stop = (value < 0 && base == 10) ? 1 : 0;
	nbr[0] = (value < 0 && base == 10) ? '-' : '\0';
	while (len >= stop)
	{
		if (ft_abs(value % base) > 9)
			nbr[len] = ft_abs(value % base) - 10 + 'A';
		else
			nbr[len] = ft_abs(value % base) + '0';
		value /= base;
		--len;
	}
}

char		*ft_itoa_base(int value, int base)
{
	int		len;
	char	*nbr;

	if (base < 2 || base > 16)
		return (NULL);
	len = count_nb(value, base);
	if (!(nbr = ft_strnew(len)))
		return (NULL);
	ft_calc(nbr, value, base, len - 1);
	return (nbr);
}
