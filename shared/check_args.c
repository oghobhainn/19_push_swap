/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:39:00 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/08 16:39:15 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared.h"

int		check_doubles(int *stack)
{
	return (1);
}

int		check_if_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (ft_isdigit(s[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}
