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

void	rr_action(int *stack_a, int *stack_b, int len_stack)
{
	rab_action(stack_a, len_stack);
	rab_action(stack_b, len_stack);
}