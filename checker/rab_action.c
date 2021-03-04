#include "checker.h"

void	rab_action(int *stack, int len_stack)
{
	int i;
	int tmp;

	i = 0;
	tmp = stack[0];
	while (i < len_stack - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[len_stack - 1] = tmp;
}

void	rr_action(t_check *c)
{
	rab_action(c->stack_a, c->len_a);
	rab_action(c->stack_b, c->len_b);
}