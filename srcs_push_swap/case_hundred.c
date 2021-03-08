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

void		sort_upper_half(t_check *c, int n, t_ps *ps)
{
	while (ps->i < n && c->len_b <= c->len_a)
	{
		if (c->stack_a[0] <= ps->median_value)
			pb(c);
		else
			rab(c->stack_a, c->len_a, 1);
		ps->i++;	
	}
	while (c->len_b > 0)
	{
		ps->min = find_min(c->stack_b, c->len_b);
		ps->max = find_max(c->stack_b, c->len_b);
		min_or_max(c->len_b, ps); 
		//on regarde si il vaut mieux chercher le min ou le max : flag_minmax vaut 1 si on cherche le min, 2 si on cherche le max
		//ps->dist aura la distance la plus courte
		//ps->direction aura la direction (1 si on monte rab, -1 si on descend rrab)
		
		// d'abord on definit si on cherche le min ou le max : lequel est le plus proche des extremites ?
		// si c'est le min : ecq il est plus proche du top ou du bot ?
			// si il est plus proche du top: on le fait remonter, transfert vers stack_a, et rotate pour qu'il soit tout en dessous
			// si il est plus proche du bot: on le fait descendre, transfert vers stack_a, et rotate pour qu'il soit tout en dessous
		// si c'est le max : ecq il est plus proche du top ou du bot ?
			// si il est plus proche du top: on le fait remonter, et transfert vers stack_a
			// si il est plus proche du bot: on le fait descendre, et transfert vers stack_a
		if (ps->flag_minmax == 1)
		{
			if (ps->direction == 1)
			{
				while (ps->dist > 0)
				{
					rab(c->stack_b, c->len_b, 2);
					ps->dist--;
				}
				pa(c);
				rab(c->stack_a, c->len_a, 1);
			}
			else
			{
				while (ps->dist > 0)
				{
					rrab(c->stack_b, c->len_b, 2);
					ps->dist--;
				}
				pa(c);
				rab(c->stack_a, c->len_a, 1);
			}
		}
		else if (ps->flag_minmax == 2)
		{
			if (ps->direction == 1)
			{
				while (ps->dist > 0)
				{
					rab(c->stack_b, c->len_b, 2);
					ps->dist--;
				}
				pa(c);
			}
			else
			{
				while (ps->dist > 0)
				{
					rrab(c->stack_b, c->len_b, 2);
					ps->dist--;
				}
				pa(c);
			}
			ps->bigs++;
		}
	}
	while (ps->bigs-- > 1)
		rab(c->stack_a, c->len_a, 1);
}

void		sort_lower_half(t_check *c, int n, t_ps *ps)
{
	while (ps->i < n && c->len_b < c->len_a)
	{
		if (c->stack_a[0] >= ps->median_value)
			pb(c);
		else
			rab(c->stack_a, c->len_a, 1);
		ps->i++;	
	}
	while (c->len_b > 0)
	{
		ps->min = find_min(c->stack_b, c->len_b);
		ps->max = find_max(c->stack_b, c->len_b);
		min_or_max(c->len_b, ps); 
		if (ps->flag_minmax == 1)
		{
			if (ps->direction == 1)
			{
				while (ps->dist > 0)
				{
					rab(c->stack_b, c->len_b, 2);
					ps->dist--;
				}
				pa(c);
				rab(c->stack_a, c->len_a, 1);
			}
			else
			{
				while (ps->dist > 0)
				{
					rrab(c->stack_b, c->len_b, 2);
					ps->dist--;
				}
				pa(c);
				rab(c->stack_a, c->len_a, 1);
			}
		}
		else if (ps->flag_minmax == 2)
		{
			if (ps->direction == 1)
			{
				while (ps->dist > 0)
				{
					rab(c->stack_b, c->len_b, 2);
					ps->dist--;
				}
				pa(c);
			}
			else
			{
				while (ps->dist > 0)
				{
					rrab(c->stack_b, c->len_b, 2);
					ps->dist--;
				}
				pa(c);
			}
			ps->bigs++;
		}
	}
	while (--ps->bigs > 0)
		rab(c->stack_a, c->len_a, 1);
}

void		case_hundred(t_check *c, int n)
{
	t_ps	ps;
	int		*sorted;

	ps.i = 0;
	ps.j = 0;
	ps.median_value = 0;
	ps.min = 0;
	ps.max = 0;
	ps.direction = 0;
	sorted = sort_array(c->stack_a, c->len_a);
	ps.median_value = find_median(sorted, c->len_a, &ps);
	sort_upper_half(c, n, &ps);
	ps.i = 0;
	ps.j = 0;
	ps.min = 0;
	ps.max = 0;
	ps.direction = 0;
	sort_lower_half(c, n, &ps);
}
