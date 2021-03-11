/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_big2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:27:02 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/11 15:27:03 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		min_or_max_big2(int len, t_big *b, int min_dist, int max_dist)
{
	if (min_dist <= max_dist)
	{
		b->flag_minmax = 1;
		b->dist = min_dist;
		if (b->min <= len / 2)
			b->direction = 1;
		else
			b->direction = -1;
	}
	else
	{
		b->flag_minmax = 2;
		b->dist = max_dist;
		if (b->max <= len / 2)
			b->direction = 1;
		else
			b->direction = -1;
	}
}

void		min_or_max_big(int len, t_big *b)
{
	int		min_dist;
	int		max_dist;

	if (b->min <= len / 2)
		min_dist = b->min;
	else
		min_dist = len - b->min;
	if (b->max <= len / 2)
		max_dist = b->max;
	else
		max_dist = len - b->max;
	min_or_max_big2(len, b, min_dist, max_dist);
}

void		find_pivots(int *sorted, int len, t_big *b)
{
	b->p0 = sorted[0];
	b->p1 = sorted[len / 4];
	b->len_p01 = len / 4;
	b->p2 = sorted[len / 2];
	b->len_p12 = len / 2 - len / 4;
	b->p3 = sorted[len / 4 * 3];
	b->len_p23 = len / 4 * 3 - len / 2;
	b->p4 = sorted[len - 1];
	b->len_p34 = len - 1 - len / 4 * 3;
}
