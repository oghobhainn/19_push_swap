/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrab_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:43:22 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/08 16:43:23 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rrab_action(int *stack, int len_stack)
{
	int	i;
	int	tmp;

	i = len_stack - 1;
	tmp = stack[len_stack - 1];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = tmp;
}

void	rrr_action(t_check *c)
{
	rrab_action(c->stack_a, c->len_a);
	rrab_action(c->stack_b, c->len_b);
}
