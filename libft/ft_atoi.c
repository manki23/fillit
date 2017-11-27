/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:54:44 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/20 16:02:14 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int j;
	int negativ;
	int nb;

	i = 0;
	j = 0;
	negativ = 0;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		negativ = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && ++j > 0)
		nb = nb * 10 + (str[i++] - '0');
	if (j > 19 && negativ)
		return (0);
	if (j > 19 && !negativ)
		return (-1);
	(negativ == 1) ? nb *= -1 : nb;
	return (nb);
}
