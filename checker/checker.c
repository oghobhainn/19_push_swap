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

int		*get_stack(int argc, char **argv)
{
	int	i;
	int j;
	int	*stack;

	i = 1;
	j = 0;
	if (!(stack = malloc_and_fill(argc - 1)))
		return (NULL);
	while (i < argc)
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
	/*if (check_doubles(stack) == 0)
	{
		free(stack);
		ft_exit("doublons\n", 2);
	}*/
	return (stack);
}

void	checker(int *stack_a, int *stack_b, int len_stack)
{
	int		again;
	char *action;

	again = 1;
	while (again == 1)
	{
		printf("stacks : \n");
		print_stack(stack_a, stack_b, len_stack);

		printf("\naction possible : [sa - sb - ss - pa - pb - ra - rb - rr - rra - rrb - rrr - q (quit)]\n\t-> ");
		get_next_line(1, &action);
		while (is_valid(action) == 0)
		{
			printf("not a valid action, try again\n");
			printf("\naction possible : [sa - sb - ss - pa - pb - ra - rb - rr - rra - rrb - rrr - q (quit)]\n\t-> ");
			get_next_line(1, &action);	
		}
		if (ft_strcmp(action, "q") == 0)
			again = 0;
		use_action(stack_a, stack_b, len_stack, action);
	}
	if (check_if_sorted(stack_a, len_stack) == 1)
		printf("sorted !\n");
	else
		printf("not sorted...\n");
	free(stack_a);
	free(stack_b);
}

int main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;

	if (argc < 2)
		ft_exit("no args\n", 1);
	if (!(stack_a = get_stack(argc, argv)))
		ft_exit("get_stack problem\n", 1);
	if (!(stack_b = malloc_and_fill(argc - 1)))
	{
		free(stack_a);
		ft_exit("malloc problem \n", 1);
	}
	checker(stack_a, stack_b, argc - 1);
	return (0);
}
