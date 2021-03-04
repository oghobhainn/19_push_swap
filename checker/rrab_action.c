#include "checker.h"

void	rrab_action(int *stack, int len_stack)
{
	int	i;
	int	tmp;

	i = len_stack - 1;
	tmp = stack[len_stack - 1];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = tmp;
}

void	rrr_action(t_check *c)
{
	rrab_action(c->stack_a, c->len_a);
	rrab_action(c->stack_b, c->len_b);
}