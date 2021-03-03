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

void	ss_action(int *stack_a, int *stack_b, int len_stack)
{
	sab_action(stack_a, len_stack);
	sab_action(stack_b, len_stack);
}