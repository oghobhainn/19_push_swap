/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:26:21 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/11 14:58:13 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			checker(t_check *c)
{
	int			again;
	static int	nb_action;
	char		*action;

	nb_action = 0;
	again = 1;
	while (again > 0)
	{
		if (c->flag_v == 1)
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
	if (c->flag_c == 1)
		print_nb_actions(nb_action);
}

void			init_check(t_check *c)
{
	c->init_len_a = 0;
	c->len_a = 0;
	c->len_b = 0;
	c->flag_v = 0;
	c->flag_c = 0;
}

int				main(int argc, char **argv)
{
	t_check		c;
	char		**args;

	init_check(&c);
	args = args_and_flags(argc, argv, &c);
	check_overflows(args);
	if (init_struct(&c, args) == 0)
		ft_exit("couldn't init struct\n", 2);
	pre_check_args(&c);
	checker(&c);
	check_if_sorted(&c);
	free(c.stack_a);
	free(c.stack_b);
	return (0);
}
