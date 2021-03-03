#include "checker.h"

int		is_valid(char *s)
{
	if (ft_strcmp(s, "sa") == 0
			|| ft_strcmp(s, "sb") == 0 // use ft_strcmp !
			|| ft_strcmp(s, "ss") == 0
			|| ft_strcmp(s, "pa") == 0
			|| ft_strcmp(s, "pb") == 0
			|| ft_strcmp(s, "ra") == 0
			|| ft_strcmp(s, "rb") == 0
			|| ft_strcmp(s, "rr") == 0
			|| ft_strcmp(s, "rra") == 0
			|| ft_strcmp(s, "rrb") == 0
			|| ft_strcmp(s, "rrr") == 0
			|| ft_strcmp(s, "q") == 0)
	{
		return (1);
	}
		return (0);
}

void	use_action(int *stack_a, int *stack_b, int len_stack, char *action)
{
	printf("we do [%s]\n", action);
	if (ft_strcmp(action, "sa") == 0)
		sab_action(stack_a, len_stack);
	else if (ft_strcmp(action, "sb") == 0)
		sab_action(stack_b, len_stack);
	else if (ft_strcmp(action, "ss") == 0)
		ss_action(stack_a, stack_b, len_stack);
/*	else if (ft_strcmp(action, "pa") == 0)
		rab_action(stack_a, len_stack);
	else if (ft_strcmp(action, "pb") == 0)
		rab_action(stack_b, len_stack);
*/	else if (ft_strcmp(action, "ra") == 0)
		rab_action(stack_a, len_stack);
	else if (ft_strcmp(action, "rb") == 0)
		rab_action(stack_b, len_stack);
	else if (ft_strcmp(action, "rr") == 0)
		rr_action(stack_a, stack_b, len_stack);
	else if (ft_strcmp(action, "rra") == 0)
		rrab_action(stack_a, len_stack);
	else if (ft_strcmp(action, "rrb") == 0)
		rrab_action(stack_b, len_stack);
	else if (ft_strcmp(action, "rrr") == 0)
		rrr_action(stack_a, stack_b, len_stack);
}
