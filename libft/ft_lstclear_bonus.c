/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:55:11 by cmcgahan          #+#    #+#             */
/*   Updated: 2019/10/23 14:48:29 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;

	if (lst && del)
	{
		list = *lst;
		while (list)
		{
			ft_lstdelone(list, del);
			list = list->next;
		}
		*lst = NULL;
	}
}
