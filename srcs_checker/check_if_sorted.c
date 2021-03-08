/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:43:50 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/08 16:44:30 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		check_if_sorted(t_check *c)
{
	int				i;

	i = 0;
	if (c->len_a != c->init_len_a)
		return (0);
	while (i < c->len_a - 1)
	{
		if (c->stack_a[i] == c->stack_a[i + 1])
		{
			free(c->stack_a);
			free(c->stack_b);
			ft_exit("There are duplicates in the list !", 2);
		}
		if (c->stack_a[i] > c->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
