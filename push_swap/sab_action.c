#include "push_swap.h"

void	sab(int *stack, int len_stack, int ssab)
{
	int	tmp;

	if (ssab == 1)
		write(1, "sa\n", 3);
	else if (ssab == 2)
		write(1, "pb\n", 3);
	if (len_stack >= 2)
	{
		tmp = stack[0];
		stack[0] = stack[1];
		stack[1] = tmp;
	}
}

void	ss(t_check *c)
{
	write(1, "ss\n", 3);
	sab(c->stack_a, c->len_a, 0);
	sab(c->stack_b, c->len_b, 0);
}