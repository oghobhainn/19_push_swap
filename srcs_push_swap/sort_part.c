/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:32:14 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/11 15:32:15 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_part3(t_check *c, t_big *b)
{
	if (b->direction == 1)
	{
		while (b->dist > 0)
		{
			rab(c->stack_b, c->len_b, 2);
			b->dist--;
		}
		pa(c);
	}
	else
	{
		while (b->dist > 0)
		{
			rrab(c->stack_b, c->len_b, 2);
			b->dist--;
		}
		pa(c);
	}
	b->bigs++;
}

void		sort_part2(t_check *c, t_big *b)
{
	if (b->flag_minmax == 1)
	{
		if (b->direction == 1)
		{
			while (b->dist > 0)
			{
				rab(c->stack_b, c->len_b, 2);
				b->dist--;
			}
			pa(c);
			rab(c->stack_a, c->len_a, 1);
		}
		else
		{
			while (b->dist > 0)
			{
				rrab(c->stack_b, c->len_b, 2);
				b->dist--;
			}
			pa(c);
			rab(c->stack_a, c->len_a, 1);
		}
	}
	else
		sort_part3(c, b);
}

void		sort_part(t_check *c, int n, t_big *b)
{
	while (b->i < n && c->len_b <= b->len_born)
	{
		if (c->stack_a[0] >= b->born1 && c->stack_a[0] < b->born2)
			pb(c);
		else
			rab(c->stack_a, c->len_a, 1);
		b->i++;
	}
	while (c->len_b > 0)
	{
		b->min = find_min(c->stack_b, c->len_b);
		b->max = find_max(c->stack_b, c->len_b);
		min_or_max_big(c->len_b, b);
		sort_part2(c, b);
	}
	while (b->bigs-- > 0)
		rab(c->stack_a, c->len_a, 1);
}
