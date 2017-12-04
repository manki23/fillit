/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:59:06 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/15 11:42:14 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s[i] == '\0' && (const char)c == '\0')
		return ((char *)s);
	while (s[i])
	{
		if (s[i] == (const char)c)
			return ((char *)s + i);
		if (s[i + 1] == (const char)c)
			return ((char *)s + (i + 1));
		++i;
	}
	return (NULL);
}
