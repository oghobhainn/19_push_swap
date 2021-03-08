/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_six.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:48:21 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/08 16:48:38 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		case_six(t_check *c, int n)
{
	int i;

	i = -1;
	while (++i < n - 3)
		pb(c);
	case_three(c->stack_a, 3, 1);
	case_three(c->stack_b, n - 3, 2);
	while (c->len_b > 0)
	{
		if (c->stack_b[0] <= c->stack_a[0])
			pa(c);
		else if (c->stack_b[0] >= c->stack_a[0]
			&& c->stack_b[0] >= c->stack_a[c->len_a - 1]
			&& c->stack_a[0] <= c->stack_a[1]
			&& c->stack_a[0] <= c->stack_a[c->len_a - 1])
			pa(c);
		else
			rab(c->stack_a, c->len_a, 1);
	}
	while (!(c->stack_a[0] <= c->stack_a[1]
				&& c->stack_a[0] <= c->stack_a[c->len_a - 1]))
	{
		rab(c->stack_a, c->len_a, 1);
	}
}
