/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:42:39 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/11 16:39:49 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared.h"

void	print_stack(t_check *c)
{
	int	i;

	i = 0;
	write(1, "stack_A	|| stack_B\n", 20);
	write(1, "------------------\n", 20);
	while (i < c->len_a || i < c->len_b)
	{
		if (i < c->len_a && i < c->len_b)
			ft_printf("    [%d] 	|| 	[%d]\n", c->stack_a[i], c->stack_b[i]);
		else if (i < c->len_a)
			ft_printf("    [%d] 	||\n", c->stack_a[i]);
		else if (i < c->len_b)
			ft_printf("        	|| 	[%d]\n", c->stack_b[i]);
		i++;
	}
	ft_printf("\n");
}
