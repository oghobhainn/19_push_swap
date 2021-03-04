#include "../shared.h"

void	print_stack(t_check *c)
{
	int	i;

	i = 0;
	while (i < c->len_a || i < c->len_b)
	{
		if (i < c->len_a && i < c->len_b)
			printf("stack_a[%d] [%d]	||	stack_b[%d] [%d]\n", i, c->stack_a[i], i, c->stack_b[i]);
		else if (i < c->len_a)
			printf("stack_a[%d] [%d]\n", i, c->stack_a[i]);
		else if (i < c->len_b)
			printf("		||	stack_b[%d] [%d]\n", i, c->stack_b[i]);
		i++;
	}
	
}