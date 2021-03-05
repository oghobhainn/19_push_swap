#include "push_swap.h"

int		check_if_sorted(t_check *c)
{
	int				i;

	i = 0;
	if (c->len_a != c->init_len_a)
		return (0);
	while (i < c->len_a - 1)
	{
		//printf("comparing [%d] and [%d]\n", c->stack_a[i], c->stack_a[i+1]);
		if (c->stack_a[i] == c->stack_a[i + 1])
		{
			free(c->stack_a);
			free(c->stack_b);
			ft_exit("There are duplicates in the list !", 2);
		}
		if (c->stack_a[i] > c->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	push_swap(t_check *c, int algo)
{
	//printf("we using the algo [%d]\n", algo);
	//if (algo == 0)
	//	bubble_sort(c, c->init_len_a);
	if (check_if_sorted(c) == 1)
		return ;
	else if (c->init_len_a <= 3)
	{
		case_three(c->stack_a, c->init_len_a, 1);
	}
	else if (c->init_len_a <= 6)
	{
		case_five(c, c->init_len_a);
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
	char		**args;
	char		**split_args;
	int			algo;

	algo = 0;
	if (argc < 2)
		ft_exit("no args\n", 2);
	if (argc == 2)
	{
		if (!(args = ft_split(argv[1], ' ')))
			return (0);
	}
	else
	{
		args = argv + 1;
	}
	if (init_struct(&c, argc, args) == 0)
		ft_exit("couldn't init struct\n", 2);
	push_swap(&c, algo);
	free(c.stack_a);
	free(c.stack_b);
	return (0);
}