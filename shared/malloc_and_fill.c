#include "../shared.h"

int		*malloc_and_fill(int size)
{
	int	*stack;

	if (!(stack = malloc(sizeof(int) * size)))
		return (NULL);
	int j = -1;
	while (++j < size)
		stack[j] = 0;
	return (stack);
}