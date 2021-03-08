/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:43:39 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/08 16:43:40 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include "../shared.h"

void	checker(t_check *c);
int		check_if_sorted(t_check *c);
int		is_valid(char *s);
void	use_action(t_check *c, char *action); 
void	sab_action(int *stack, int len_stack);
void	ss_action(t_check *c);
int		pa_action(t_check *c);
int		pb_action(t_check *c);
void	rab_action(int *stack, int len_stack);
void	rr_action(t_check *c);
void	rrab_action(int *stack, int len_stack);
void	rrr_action(t_check *c);

#endif
