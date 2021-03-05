#include "push_swap.h"

void	rab(int *stack, int len_stack, int rrab)
{
	int i;
	int tmp;

	if (rrab == 1)
		write(1, "ra\n", 3);
	else if (rrab == 2)
		write(1, "rb\n", 3);
	i = 0;
	tmp = stack[0];
	while (i < len_stack - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[len_stack - 1] = tmp;
}

void	rr(t_check *c)
{
	write(1, "rr\n", 3);
	rab(c->stack_a, c->len_a, 0);
	rab(c->stack_b, c->len_b, 0);
}