/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:57:30 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/11 14:57:35 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			check_overflows(char **args)
{
	int			i;

	i = 0;
	while (args[i])
	{
		if (ft_strlen(args[i]) > ft_strlen("-2147483648"))
			ft_exit("Error: wrong arg (possibly overflow)\n", 2);
		else if (ft_strlen(args[i]) == ft_strlen("-2147483648"))
		{
			if (args[i][0] != '-' || args[i][0] != '+')
				ft_exit("Error: wrong arg (possibly overflow)\n", 2);
			else
			{
				if (ft_atoll(args[i]) > INT_MAX || ft_atoll(args[i]) < INT_MIN)
					ft_exit("Error: overflow\n", 2);
			}
		}
		i++;
	}
}

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
