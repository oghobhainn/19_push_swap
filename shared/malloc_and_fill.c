/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_and_fill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:41:19 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/08 16:41:34 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared.h"

int		*malloc_and_fill(int size)
{
	int	j;
	int	*stack;

	if (!(stack = malloc(sizeof(int) * size)))
		return (NULL);
	j = -1;
	while (++j < size)
		stack[j] = 0;
	return (stack);
}
