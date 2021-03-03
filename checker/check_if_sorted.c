#include "checker.h"

int		check_if_sorted(int *stack_a, int len_stack)
{
	int				i;

	i = 0;
	while (i < len_stack - 1)
	{
		printf("comparing [%d] and [%d]\n", stack_a[i], stack_a[i+1]);
		if (stack_a[i] > stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}