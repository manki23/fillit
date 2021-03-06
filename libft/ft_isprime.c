/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 13:19:29 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/15 13:35:22 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isprime(unsigned int nb)
{
	unsigned int i;

	if (nb == 0 || nb == 1)
		return (0);
	i = 2;
	while ((i * i) <= nb)
	{
		if (i != nb && (nb % i) == 0)
			return (0);
		++i;
	}
	return (1);
}
