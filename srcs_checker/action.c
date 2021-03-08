/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:43:44 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/08 16:44:13 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		is_valid(char *s)
{
	if (ft_strcmp(s, "sa") == 0
			|| ft_strcmp(s, "sb") == 0
			|| ft_strcmp(s, "ss") == 0
			|| ft_strcmp(s, "pa") == 0
			|| ft_strcmp(s, "pb") == 0
			|| ft_strcmp(s, "ra") == 0
			|| ft_strcmp(s, "rb") == 0
			|| ft_strcmp(s, "rr") == 0
			|| ft_strcmp(s, "rra") == 0
			|| ft_strcmp(s, "rrb") == 0
			|| ft_strcmp(s, "rrr") == 0
			|| ft_strcmp(s, "q") == 0)
	{
		return (1);
	}
	return (0);
}

void	use_action(t_check *c, char *action)
{
	if (ft_strcmp(action, "sa") == 0)
		sab_action(c->stack_a, c->len_a);
	else if (ft_strcmp(action, "sb") == 0)
		sab_action(c->stack_b, c->len_b);
	else if (ft_strcmp(action, "ss") == 0)
		ss_action(c);
	else if (ft_strcmp(action, "pa") == 0)
		pa_action(c);
	else if (ft_strcmp(action, "pb") == 0)
		pb_action(c);
	else if (ft_strcmp(action, "ra") == 0)
		rab_action(c->stack_a, c->len_a);
	else if (ft_strcmp(action, "rb") == 0)
		rab_action(c->stack_b, c->len_b);
	else if (ft_strcmp(action, "rr") == 0)
		rr_action(c);
	else if (ft_strcmp(action, "rra") == 0)
		rrab_action(c->stack_a, c->len_a);
	else if (ft_strcmp(action, "rrb") == 0)
		rrab_action(c->stack_b, c->len_b);
	else if (ft_strcmp(action, "rrr") == 0)
		rrr_action(c);
}
