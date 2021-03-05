#include "push_swap.h"

void		case_five(t_check *c, int n)
{
	pb(c);
	if (n == 5)
		pb(c);
	case_three(c, 3);
	while (c->len_b > 0)
	{
		if (c->stack_b[0] <= c->stack_a[0] && c->stack_a[0] <= c->stack_a[1])
			pa(c);
		else if (c->stack_b[0] >= c->stack_a[0] && c->stack_b[0] >= c->stack_a[c->len_a - 1])
		{
			rab(c->stack_a, c->len_a, 1);
		}
		else if (c->stack_b[0] >= c->stack_a[0] && c->stack_b[0] <= c->stack_a[c->len_a - 1])
			rab(c->stack_a, c->len_a, 1);
		else
		{
			rrab(c->stack_a, c->len_a, 1);
		}
	}
	while (c->stack_a[0] >= c->stack_a[c->len_a - 1])
		rrab(c->stack_a, c->len_a, 1);
}