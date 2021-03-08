/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:50:12 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/08 16:50:19 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_median(int *sorted, int len, t_ps *ps)
{
	ps->median_value = sorted[len / 2];
	return (ps->median_value);
}
