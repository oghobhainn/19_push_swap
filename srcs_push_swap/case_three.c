/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:48:51 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/11 15:05:30 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		case_two(int *stack, int n, int ab)
{
	int		top;
	int		bot;

	top = stack[0];
	bot = stack[n - 1];
	if (top > bot)
		sab(stack, n, ab);
}

void		case_three(int *stack, int n, int ab)
{
	int		top;
	int		mid;
	int		bot;

	top = stack[0];
	bot = stack[n - 1];
	mid = stack[1];
	if (top > mid && top < bot)
		sab(stack, n, ab);
	else if (top > mid && top > bot && mid > bot)
	{
		sab(stack, n, ab);
		rrab(stack, n, ab);
	}
	else if (top > mid && top > bot && mid < bot)
		rab(stack, n, ab);
	else if (top < mid && mid > bot && top < bot)
	{
		sab(stack, n, ab);
		rab(stack, n, ab);
	}
	else if (top < mid && mid > bot && top > bot)
		rrab(stack, n, ab);
}
