#include "push_swap.h"

void		case_three(t_check *c, int n)
{
	int		top;
	int		mid;
	int		bot;

	top = c->stack_a[0];
	bot = c->stack_a[n - 1];
	if (n == 2 && top < bot)
		sab(c->stack_a, c->len_a, 1);
	else
	{
		mid = c->stack_a[1];
		if (top > mid && top < bot)
			sab(c->stack_a, c->len_a, 1);
		else if (top > mid && top > bot && mid > bot)
		{
			sab(c->stack_a, c->len_a, 1);
			rrab(c->stack_a, c->len_a, 1);
		}
		else if (top > mid && top > bot && mid < bot)
			rab(c->stack_a, c->len_a, 1);
		else if (top < mid && mid > bot && top < bot)
		{
			sab(c->stack_a, c->len_a, 1);
			rab(c->stack_a, c->len_a, 1);
		}
		else if (top < mid && mid > bot && top > bot)
			rrab(c->stack_a, c->len_a, 1);
	}
}