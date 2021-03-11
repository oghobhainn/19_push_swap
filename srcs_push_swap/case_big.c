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

void		find_pivots(int *sorted, int len, t_big *b)
{
	b->p1 = sorted[len / 4];
	b->len_p01 = len / 4;
	b->p2 = sorted[len / 2];
	b->len_p12 = len / 2 - len / 4;
	b->p3 = sorted[len / 4 * 3];
	b->len_p23 = len / 4 * 3 - len / 2;
	b->p4 = sorted[len - 1];
	b->len_p34 = len - 1 - len / 4 * 3;
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
		else if (b->flag_minmax == 2)
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
	}
	while (b->bigs-- > 0)
		rab(c->stack_a, c->len_a, 1);

}

void		sort_first_part(t_check *c, int n, t_big *b)
{
	while (b->i < n && c->len_b <= b->len_p01)
	{
		if (c->stack_a[0] < b->p1)
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
		else if (b->flag_minmax == 2)
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
	}
	while (b->bigs-- > 0)
		rab(c->stack_a, c->len_a, 1);
}

void		sort_second_part(t_check *c, int n, t_big *b)
{
	while (b->i < n && c->len_b <= b->len_p12)
	{
		if (c->stack_a[0] >= b->p1 && c->stack_a[0] < b->p2)
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
		else if (b->flag_minmax == 2)
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
	}
	while (b->bigs-- > 0)
		rab(c->stack_a, c->len_a, 1);
}

void		sort_third_part(t_check *c, int n, t_big *b)
{
//	while (c->stack_a[0] < b->p2)
//		rrab(c->stack_a, c->len_a, 1);
	while (b->i < n && c->len_b <= b->len_p23)
	{
		if (c->stack_a[0] >= b->p2 && c->stack_a[0] < b->p3)
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
		else if (b->flag_minmax == 2)
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
	}
	while (b->bigs-- > 0)
		rab(c->stack_a, c->len_a, 1);
}

void		sort_fourth_part(t_check *c, int n, t_big *b)
{
	while (b->i < n && c->len_b <= b->len_p34)
	{
		if (c->stack_a[0] >= b->p3)
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
		else if (b->flag_minmax == 2)
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
	}
	while (b->bigs-- > 0)
		rab(c->stack_a, c->len_a, 1);
}

void		case_big(t_check *c, int n)
{
	int		nb_partitions = n / 100;
	
	t_big	b;
	int		*sorted;

	init_big(&b);
	sorted = sort_array(c->stack_a, c->len_a);
	find_pivots(sorted, c->len_a, &b);
	sort_first_part(c, n, &b);
	reinit_big(&b);
	sort_second_part(c, n, &b);
	reinit_big(&b);
	sort_third_part(c, n, &b);
	reinit_big(&b);
	sort_fourth_part(c, n, &b);
}
