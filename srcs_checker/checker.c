/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:26:21 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/03 14:36:04 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker(t_check *c)
{
	int		again;
	static int		nb_action;
	char	*action;

	nb_action = 0;
	again = 1;
	while (again > 0)
	{
		print_stack(c);
		again = get_next_line(0, &action);
		while (is_valid(action) == 0 && again != 0)
		{
			write(1, action, ft_strlen(action));
			write(1, "\n", 1);
			free(action);
			again = get_next_line(0, &action);	
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
	checker(&c);
	free(c.stack_a);
	free(c.stack_b);
	return (0);
}
