/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:56:52 by cmcgahan          #+#    #+#             */
/*   Updated: 2019/10/28 10:32:26 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newlist;

	if (!(newlist = (t_list *)malloc(sizeof(t_list) + 1)))
		return (NULL);
	if (!content)
		newlist->content = NULL;
	else
	{
		if (!(newlist->content = (void*)malloc(sizeof(content) + 1)))
			return (NULL);
		ft_memcpy(newlist->content, content, ft_strlen(content) + 1);
	}
	newlist->next = NULL;
	return (newlist);
}
