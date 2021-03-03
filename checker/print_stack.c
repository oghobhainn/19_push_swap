#include "checker.h"

void	print_stack(int *stack_a, int *stack_b, int len_stack)
{
	int	i;

	i = 0;
	while (i < len_stack)
	{
		printf("stack_a[%d] [%d]	||	stack_b[%d] [%d]\n", i, stack_a[i], i, stack_b[i]);
		i++;
	}
	
}