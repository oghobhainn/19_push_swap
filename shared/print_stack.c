#include "../shared.h"

void	print_stack(t_check *c)
{
	int	i;

	i = 0;
	printf("stack_A	|| stack_B\n");
	printf("------------------\n");
	while (i < c->len_a || i < c->len_b)
	{
		if (i < c->len_a && i < c->len_b)
			printf("    [%d] 	|| 	[%d]\n", c->stack_a[i], c->stack_b[i]);
		else if (i < c->len_a)
			printf("    [%d] 	||\n", c->stack_a[i]);
		else if (i < c->len_b)
			printf("        	|| 	[%d]\n", c->stack_b[i]);
		i++;
	}
	printf("\n");
	
}