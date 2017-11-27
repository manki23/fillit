/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:04:21 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/17 13:58:40 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *elem;

	if (!(elem = malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		elem->content_size = 0;
		elem->content = NULL;
	}
	else
	{
		elem->content = ft_strdup(content);
		elem->content_size = content_size;
	}
	elem->next = NULL;
	return (elem);
}
