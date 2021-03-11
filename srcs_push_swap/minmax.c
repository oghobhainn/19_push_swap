/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:38:32 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/11 15:38:32 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_max(int *stack, int n)
{
	int		i;
	int		max_ix;
	int		max;

	i = 0;
	max_ix = 0;
	max = stack[0];
	while (i < n)
	{
		if (stack[i] > max)
		{
			max_ix = i;
			max = stack[i];
		}
		i++;
	}
	return (max_ix);
}

int			find_min(int *stack, int n)
{
	int		i;
	int		min_ix;
	int		min;

	i = 0;
	min_ix = 0;
	min = stack[0];
	while (i < n)
	{
		if (stack[i] < min)
		{
			min_ix = i;
			min = stack[i];
		}
		i++;
	}
	return (min_ix);
}

void		min_or_max2(int len, t_ps *ps, int min_dist, int max_dist)
{
	if (min_dist <= max_dist)
	{
		ps->flag_minmax = 1;
		ps->dist = min_dist;
		if (ps->min <= len / 2)
			ps->direction = 1;
		else
			ps->direction = -1;
	}
	else
	{
		ps->flag_minmax = 2;
		ps->dist = max_dist;
		if (ps->max <= len / 2)
			ps->direction = 1;
		else
			ps->direction = -1;
	}
}

void		min_or_max(int len, t_ps *ps)
{
	int		min_dist;
	int		max_dist;

	if (ps->min <= len / 2)
		min_dist = ps->min;
	else
		min_dist = len - ps->min;
	if (ps->max <= len / 2)
		max_dist = ps->max;
	else
		max_dist = len - ps->max;
	min_or_max2(len, ps, min_dist, max_dist);
}
