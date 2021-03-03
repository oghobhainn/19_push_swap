/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:54:51 by cmcgahan          #+#    #+#             */
/*   Updated: 2019/10/23 14:46:41 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (alst && new && (*alst != new))
	{
		tmp = *alst;
		if (*alst == NULL)
			*alst = new;
		else
		{
			*alst = new;
			new->next = tmp;
		}
	}
}
