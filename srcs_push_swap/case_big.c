/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:53:27 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/11 15:11:59 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		reinit_big(t_big *b, int lenborn, int born1, int born2)
{
	b->i = 0;
	b->j = 0;
	b->min = 0;
	b->max = 0;
	b->dist = 0;
	b->min_dist = 0;
	b->max_dist = 0;
	b->direction = 0;
	b->flag_minmax = 0;
	b->smalls = 0;
	b->bigs = 0;
	b->len_born = lenborn;
	b->born1 = born1;
	b->born2 = born2;
}

void		init_big(t_big *b)
{
	b->i = 0;
	b->j = 0;
	b->p1 = 0;
	b->p2 = 0;
	b->p3 = 0;
	b->p4 = 0;
	b->min = 0;
	b->max = 0;
	b->dist = 0;
	b->min_dist = 0;
	b->max_dist = 0;
	b->direction = 0;
	b->flag_minmax = 0;
	b->smalls = 0;
	b->bigs = 0;
}

void		case_big(t_check *c, int n)
{
	t_big	b;
	int		*sorted;

	init_big(&b);
	sorted = sort_array(c->stack_a, c->len_a);
	find_pivots(sorted, c->len_a, &b);
	b.len_born = b.len_p01;
	b.born1 = b.p0;
	b.born2 = b.p1;
	sort_part(c, n, &b);
	reinit_big(&b, b.len_p12, b.p1, b.p2);
	sort_part(c, n, &b);
	reinit_big(&b, b.len_p23, b.p2, b.p3);
	sort_part(c, n, &b);
	reinit_big(&b, b.len_p34, b.p3, b.p4 + 1);
	sort_part(c, n, &b);
}
