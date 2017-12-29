/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:13:31 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/27 09:50:34 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if ((char *)src > (char *)dst)
		while (++i < len)
			*(char *)(dst + i) = *(char *)(src + i);
	else
		while (++i < len)
			*(char *)(dst + (len - 1 - i)) = *(char *)(src + (len - 1 - i));
	return (dst);
}
