#include "push_swap.h"

int		find_median(int *sorted, int len, t_ps *ps)
{
	ps->median_value = sorted[len / 2];
	return (ps->median_value);
}