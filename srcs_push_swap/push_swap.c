/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:51:04 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/11 15:06:01 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_if_sorted(t_check *c)
{
	int				i;

	i = 0;
	if (c->len_a != c->init_len_a)
		return (0);
	while (i < c->len_a - 1)
	{
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

void	push_swap(t_check *c)
{
	if (check_if_sorted(c) == 1)
		return ;
	if (c->init_len_a == 2)
		case_two(c->stack_a, c->init_len_a, 1);
	else if (c->init_len_a == 3)
		case_three(c->stack_a, c->init_len_a, 1);
	else if (c->init_len_a <= 6)
		case_six(c, c->init_len_a);
	else
		case_big(c, c->init_len_a);
}

int		main(int argc, char **argv)
{
	t_check		c;
	char		**args;
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
	if (init_struct(&c, args) == 0)
		ft_exit("couldn't init struct\n", 2);
	push_swap(&c);
	free(c.stack_a);
	free(c.stack_b);
	return (0);
}
