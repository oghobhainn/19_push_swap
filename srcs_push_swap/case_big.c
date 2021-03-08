/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:53:27 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/08 16:53:37 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		case_big(t_check *c, int n)
{
	int		nb_partitions = n / 100;
	//nb partitions serait egal a centaines / 2 (100 -> 2, 100-200 -> 4, 400-500 -> 10)
	//on trouve suffisament de sous medianes (pivots) en fonction du cas
	//on procede comme pour avant mais en faisant soit les partitions centrales d'abord, soit les partitions extremes... je sais pas encore

	printf("this is a looot of numbers\n");
}
