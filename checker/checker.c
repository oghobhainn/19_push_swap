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
	char	*action;

	again = 1;
	while (again > 0)
	{
		print_stack(c);

//		printf("\naction possible : [sa - sb - ss - pa - pb - ra - rb - rr - rra - rrb - rrr - q (quit)]\n\t-> ");
		again = get_next_line(0, &action);
		while (is_valid(action) == 0 && again != 0)
		{
//			printf("not a valid action, try again\n");
//			printf("\naction possible : [sa - sb - ss - pa - pb - ra - rb - rr - rra - rrb - rrr - q (quit)]\n\t-> ");
			again = get_next_line(0, &action);	
		}
		if (again != 0)
			use_action(c, action);
	}
	if (check_if_sorted(c) == 1)
		printf("sorted !\n");
	else
		printf("not sorted...\n");
}

int		main(int argc, char **argv)
{
	char		**split_args;
	t_check 	c;

	if (argc < 2)
		ft_exit("no args\n", 2);
	if (!(split_args = ft_split(argv[1], ' ')))
		return (0);
	if (init_struct(&c, argc, split_args) == 0)
		ft_exit("couldn't init struct\n", 2);
	checker(&c);
	free(c.stack_a);
	free(c.stack_b);
	return (0);
}
