#include "checker.h"

void	sab_action(int *stack, int len_stack)
{
	int	tmp;

	if (len_stack >= 2)
	{
		tmp = stack[0];
		stack[0] = stack[1];
		stack[1] = tmp;
	}
}

void	ss_action(t_check *c)
{
	sab_action(c->stack_a, c->len_a);
	sab_action(c->stack_b, c->len_b);
}