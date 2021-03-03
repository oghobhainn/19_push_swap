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

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

void	print_stack(int *stack_a, int *stack_b, len_stack)
{
	int	i;

	i = 0;
	while (i < len_stack)
	{
		printf("stack_a[%d] [%d]	||	stack_b[%d] [%d]\n", i, stack_a[i], i, stack_b[i]);
		i++;
	}
	
}

int		check_doubles(int *stack)
{
	return (1);
}

int		check_if_number(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
//		printf("trying with [%c]\n", s[i]);
		if (isdigit(s[i]) != 1) // mettre ft_isdigt !
			return (0);
		i++;
	}
	return (1);
}

int		*get_stack(int argc, char **argv)
{
	int	i;
	int j;
	int	*stack;

	i = 1;
	j = 0;
	if (!(stack = malloc(sizeof(int) * (argc - 2))))
		return (NULL);
	while (i < argc)
	{
		if (check_if_number(argv[i]) == 1)
			stack[j] = atoi(argv[i]); //mettre ft_Atoi !
		else
		{
			write(2, "invalid argument\n", 17);
			free(stack);
			return (NULL);
		}
		i++;
		j++;
	}
	if (check_doubles(stack) == 0)
	{
		write(2, "doublons !\n", 11);
		free(stack);
		return (NULL);
	}
	return (stack);
}

int		check_if_sorted(int *stack_a, int len_stack)
{
	int				i;

	i = 0;
	while (i < len_stack)
	{
		printf("comparing [%d] and [%d]\n", stack_a[i], stack_a[i+1]);
		if (stack_a[i] > stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		is_valid(char *s)
{
	if (strcmp(s, "sa") == 0
			|| strcmp(s, "sb") == 0 // use ft_strcmp !
			|| strcmp(s, "ss") == 0
			|| strcmp(s, "pa") == 0
			|| strcmp(s, "pb") == 0
			|| strcmp(s, "ra") == 0
			|| strcmp(s, "rb") == 0
			|| strcmp(s, "rr") == 0
			|| strcmp(s, "rra") == 0
			|| strcmp(s, "rrb") == 0
			|| strcmp(s, "rrr") == 0)
	{
		return (1);
	}
		return (0);
}

void	checker(int *stack_a, int *stack_b, int len_stack)
{
	char action[1000];

	printf("\naction possible : sa - sb - ss - pa - pb - ra - rb - rr - rra - rrb - rrr\n\t-> ");
	scanf("%s", action); // use get_next_line
	while (is_valid(action) == 0)
	{
		printf("not a valid action, try again\n");
		scanf("%s", action);
	}
	printf("you choose to [%s]\n", action);
//	use_action(stack_a, stack_b, len_stack,)
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
	{
		write(2, "no args\n", 8);
		return (0);
	}
	if (!(stack_a = get_stack(argc, argv)))
	{
		write(2, "problem\n", 8);
		return (0);
	}
	if (!(stack_b = malloc(sizeof(int) * (argc - 2))))
	{
		free(stack_a);
		return (0);
	}
	int j = -1;
	while (++j < argc - 2)
		stack_b[j] = 0;

	print_stack(stack_a, stack_b, argc - 2);

	checker(stack_a, stack_b, argc - 2);
	return (0);
}
