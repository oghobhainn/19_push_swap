#include "../checker/checker.h"
/*
int		find_median_index()
{

}
*/
void	push_swap(t_check *c)
{
	if (c->init_len_a <= 3)
	{
		printf("case with 2 or 3 numbers\n");
	}
	else if (c->init_len_a <= 5)
	{
		printf("case with 4 or 5 numbers\n");
	}
	else if (c->init_len_a <= 100)
	{
		printf("case with less than 100 numbers\n");
	}
	else
		printf("more than 100 numbers\n");
}


int		main(int argc, char **argv)
{
	t_check		c;
	char		**split_args;

	if (argc < 2)
		ft_exit("no args\n", 2);
	if (!(split_args = ft_split(argv[1], ' ')))
		return (0);
	if (init_struct(&c, argc, split_args) == 0)
		ft_exit("couldn't init struct\n", 2);
	push_swap(&c);
	free(c.stack_a);
	free(c.stack_b);
	return (0);
}