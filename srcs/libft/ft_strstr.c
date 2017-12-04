/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:10:10 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/09 17:10:30 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int			i;
	const char	*new_haystack;
	const char	*s1;
	const char	*s2;

	i = 0;
	new_haystack = haystack;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (new_haystack[i] != '\0')
	{
		s1 = new_haystack;
		s2 = needle;
		while ((s1[i] != '\0') && (s2[i] != '\0') && (s1[i] == s2[i]))
		{
			s1++;
			s2++;
		}
		if (s2[i] == '\0')
			return ((char *)new_haystack);
		new_haystack++;
	}
	return (NULL);
}
