/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:56:27 by cmcgahan          #+#    #+#             */
/*   Updated: 2019/10/24 14:47:57 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	*result;
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	new = lst;
	if (!(result = ft_lstnew((*f)(new->content))))
		return (NULL);
	new = new->next;
	while (new)
	{
		tmp = ft_lstnew((*f)(new->content));
		ft_lstadd_back(&result, tmp);
		new = new->next;
	}
	return (result);
}
