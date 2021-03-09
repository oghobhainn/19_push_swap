/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:53:27 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/08 16:53:37 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		find_pivots(sorted, c->len_a, &b)
{
	b->p1 = sorted[len / 4];
	b->p2 = sorted[len / 2];
	b->p2 = sorted[len / 2 * 3];
	b->p3 = sorted[len];
}

void		reinit_big(t_big *b)
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
	int		nb_partitions = n / 100;
	//nb partitions serait egal a centaines / 2 (100 -> 2, 100-200 -> 4, 400-500 -> 10)
	//on trouve suffisament de sous medianes (pivots) en fonction du cas
	//on procede comme pour avant mais en faisant soit les partitions centrales d'abord, soit les partitions extremes... je sais pas encore

	t_big	b;
	int		*sorted;

	init_big(&b);
	sorted = sort_array(c->stack_a, c->len_a);
	find_pivots(sorted, c->len_a, &b);
	sort_first_part(c, n, &b);
//	reinit_big(&b);
//	sort_second_part(c, n, &b);
//	reinit_big(&b);
//	sort_third_part(c, n, &b);
//	reinit_big(&b);
//	sort_fourth_part(c, n, &b);
}
