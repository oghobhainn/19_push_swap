/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <cmcgahan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:23:41 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/08 11:13:47 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared.h"

int		*sort_array(int *unsorted, int len)
{
	int	i;
	int	j;
	int	tmp;
	int	*sorted;

	sorted = malloc(sizeof(int) * len);
	i = -1;
	while (++i < len)
		sorted[i] = unsorted[i];
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (sorted[i] > sorted[j])
			{
				tmp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (sorted);
}

