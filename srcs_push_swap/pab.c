/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:50:29 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/08 16:50:51 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	intptrcpy(int *src, int *dest, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
}

int		add_element(t_check *c, char stack, int new_elem)
{
	int	*new_stack;

	if (stack == 'a')
	{
		if (!(new_stack = malloc(sizeof(int) * (c->len_a + 1))))
			return (0);
		new_stack[0] = new_elem;
		intptrcpy(c->stack_a, new_stack + 1, c->len_a);
		c->stack_a = new_stack;
		c->len_a++;
	}
	else if (stack == 'b')
	{
		if (!(new_stack = malloc(sizeof(int) * (c->len_b + 1))))
			return (0);
		new_stack[0] = new_elem;
		intptrcpy(c->stack_b, new_stack + 1, c->len_b);
		c->stack_b = new_stack;
		c->len_b++;
	}
	return (1);
}

int		pb(t_check *c)
{
	int	*new_stack;

	write(1, "pb\n", 3);
	if (c->len_a > 1)
	{
		if (!(new_stack = malloc(sizeof(int) * (c->len_a - 1))))
			return (0);
		intptrcpy(c->stack_a + 1, new_stack, c->len_a - 1);
		if (!(add_element(c, 'b', c->stack_a[0])))
			return (0);
		c->len_a--;
		free(c->stack_a);
		c->stack_a = new_stack;
	}
	else if (c->len_a == 1)
	{
		if (!(new_stack = malloc(sizeof(int) * (1))))
			return (0);
		if (!(add_element(c, 'b', c->stack_a[0])))
			return (0);
		c->len_a--;
		free(c->stack_a);
		c->stack_a = new_stack;
	}
	return (1);
}

int		pa(t_check *c)
{
	int	*new_stack;

	write(1, "pa\n", 3);
	if (c->len_b > 1)
	{
		if (!(new_stack = malloc(sizeof(int) * (c->len_b - 1))))
			return (0);
		intptrcpy(c->stack_b + 1, new_stack, c->len_b - 1);
		if (!(add_element(c, 'a', c->stack_b[0])))
			return (0);
		c->len_b--;
		free(c->stack_b);
		c->stack_b = new_stack;
	}
	else if (c->len_b == 1)
	{
		if (!(new_stack = malloc(sizeof(int) * (1))))
			return (0);
		if (!(add_element(c, 'a', c->stack_b[0])))
			return (0);
		c->len_b--;
		free(c->stack_b);
		c->stack_b = new_stack;
	}
	return (1);
}
