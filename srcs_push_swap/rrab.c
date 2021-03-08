/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrab.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:53:03 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/08 16:53:11 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrab(int *stack, int len_stack, int rrrab)
{
	int	i;
	int	tmp;

	if (rrrab == 1)
		write(1, "rra\n", 4);
	else if (rrrab == 2)
		write(1, "rrb\n", 4);
	i = len_stack - 1;
	tmp = stack[len_stack - 1];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = tmp;
}

void	rrr(t_check *c)
{
	write(1, "rrr\n", 4);
	rrab(c->stack_a, c->len_a, 0);
	rrab(c->stack_b, c->len_b, 0);
}
