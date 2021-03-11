/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:57:19 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/11 14:57:25 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			print_nb_actions(int nb)
{
	ft_putstr_fd("We've needed ", 1);
	ft_putnbr_fd(nb, 1);
	ft_putstr_fd(" actions to sort the array,\n", 1);
}
