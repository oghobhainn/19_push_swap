/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <cmcgahan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:23:41 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/06 14:41:00 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*sort_array(int *unsorted, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (unsorted[i] > unsorted[j])
			{
				tmp = unsorted[i];
				unsorted[i] = unsorted[j];
				unsorted[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (unsorted);
}
/*
int main()
{
	int n = 10;
	int unsorted[10] = {5,4,9,6,1,3,7,8,2,0};
	int	*sorted;
	sorted = sort_array(unsorted, 10);
	for (int i = 0; i < n; ++i)
		printf("%d\n", unsorted[i]);
	return (0);
}*/
