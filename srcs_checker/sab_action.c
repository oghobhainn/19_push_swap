/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sab_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:43:25 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/08 16:43:26 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sab_action(int *stack, int len_stack)
{
	int	tmp;

	if (len_stack >= 2)
	{
		tmp = stack[0];
		stack[0] = stack[1];
		stack[1] = tmp;
	}
}

void	ss_action(t_check *c)
{
	sab_action(c->stack_a, c->len_a);
	sab_action(c->stack_b, c->len_b);
}
