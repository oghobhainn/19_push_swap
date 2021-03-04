#include "../shared.h"

void	ft_exit(char *msg, int a)
{
	if (a != 0)
	{
		ft_putstr_fd("problem !\t->\t", 2);
		ft_putstr_fd(msg, 2);
	}
	else
	{
		ft_putstr_fd("casually exiting :-)\n", 1);
	}
	exit(a);
}