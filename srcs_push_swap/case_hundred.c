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

void		case_hundred(t_check *c, int n)
{
	int		i;
	int		j;
	int		median;
	int		min;
	int		max;
	int		direction;

	i = 0;
	median = 1000;
	while (i < n)
	{
		if (c->stack_a[0] <= median)
			pb(c);
		else
			rab(c->stack_a, c->len_a, 1);
		i++;
	}
	while (c->len_b > 0)
	{
		min = find_min(c->stack_b, c->len_b);
		max = find_max(c->stack_b, c->len_b);
		//printf("min is at index [%d]\n", min);
//		printf("max is at index [%d]\n", max);
/*		if (min > c->len_b / 2)
		{
			printf("we go up !\n");
			direction = 1;
		}
		else
		{
			printf("we go down !\n");
			direction = -1;
		}
*/		
		if (max > c->len_b / 2)
		{
//			printf("we go up !\n");
			direction = 1;
		}
		else
		{
//			printf("we go down !\n");
			direction = -1;
		}
		j = max;
		while (j > 0 && j < c->len_b)
		{
			if (direction == 1)
			{
				j++;
				rrab(c->stack_b, c->len_b, 2);
			}
			else
			{
				j--;
				rab(c->stack_b, c->len_b, 2);
			}
		}
		pa(c);
	}
}