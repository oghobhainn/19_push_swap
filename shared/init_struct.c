/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:41:11 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/08 16:41:15 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared.h"

int		init_struct(t_check *c, int argc, char **argv)
{
	c->len_a = count_args(argv);
	c->init_len_a = c->len_a;
	c->len_b = 0;
	if (!(c->stack_a = get_stack(c->len_a, argv)))
		ft_exit("get_stack problem\n", 2);
	if (!(c->stack_b = malloc_and_fill(1)))
	{
		free(c->stack_a);
		ft_exit("malloc problem \n", 2);
	}
	return (1);
}
