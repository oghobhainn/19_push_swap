#include "../shared.h"

int		*get_stack(int len_a, char **argv)
{
	int	i;
	int j;
	int	*stack;

	i = 0;
	j = 0;
	if (!(stack = malloc_and_fill(len_a)))
		return (NULL);
	while (i < len_a)
	{
		if (check_if_number(argv[i]) == 1)
			stack[j] = ft_atoi(argv[i]);
		else
		{
			free(stack);
			ft_exit("invalid argument\n", 2);
		}
		i++;
		j++;
	}
	return (stack);
}
