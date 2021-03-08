/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:26:21 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/08 16:45:26 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
/*
void			check_overflows(char **args)
{
	long		i;

	i = 0;
	while (args[i])
	{

	}
}
*/
void			check_duplicates(t_check *c)
{
	int			i;

	i = 0;
	while (i < c->len_a - 1)
	{
		if (c->stack_a[i] == c->stack_a[i + 1])
		{
			free(c->stack_a);
			free(c->stack_b);
			ft_exit("Error: Duplicates\n", 2);
		}
		i++;
	}
}

void			pre_check_args(t_check *c)
{
	int			*sorted;

	sorted = sort_array(c->stack_a, c->len_a);
	check_duplicates(c);
}

void			checker(t_check *c)
{
	int			again;
	static int	nb_action;
	char		*action;

	nb_action = 0;
	again = 1;
	while (again > 0)
	{
		print_stack(c);
		again = get_next_line(0, &action);
		if (again != 0 && is_valid(action) == 0)
		{
			free(action);
			ft_exit("Error: wrong command\n", 2);
		}
		if (again != 0)
		{
			nb_action++;
			use_action(c, action);
			free(action);
		}
	}
	printf("we used [%d] actions to sort it\n", nb_action);
	if (check_if_sorted(c) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int		main(int argc, char **argv)
{
	char		**args;
	char		**split_args;
	t_check 	c;

	if (argc < 2)
		ft_exit("Error: No args\n", 2);
	if (argc == 2)
	{
		if (!(args = ft_split(argv[1], ' ')))
			return (0);
	}
	else
	{
		args = argv + 1;
	}
//	check_overflows(args);
	if (init_struct(&c, argc, args) == 0)
		ft_exit("couldn't init struct\n", 2);
	pre_check_args(&c);
	checker(&c);
	free(c.stack_a);
	free(c.stack_b);
	return (0);
}
