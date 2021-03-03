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

void	rrr_action(int *stack_a, int *stack_b, int len_stack)
{
	rrab_action(stack_a, len_stack);
	rrab_action(stack_b, len_stack);
}