/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:51:35 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/11 15:05:09 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define EXAMPLE 0
# include "../shared.h"

typedef struct	s_big
{
	int			i;
	int			j;
	int			p0;
	int			p1;
	int			p2;
	int			p3;
	int			p4;
	int			len_p01;
	int			len_p12;
	int			len_p23;
	int			len_p34;
	int			born1;
	int			born2;
	int			len_born;
	int			min;
	int			max;
	int			dist;
	int			min_dist;
	int			max_dist;
	int			direction;
	int			flag_minmax;
	int			smalls;
	int			bigs;
}				t_big;

typedef struct	s_ps
{
	int			i;
	int			j;
	int			min;
	int			max;
	int			median;
	int			median_value;
	int			dist;
	int			min_dist;
	int			max_dist;
	int			search;
	int			direction;
	int			flag_minmax;
	int			smalls;
	int			bigs;
}				t_ps;

void			rrab(int *stack, int len_stack, int rrrab);
void			rrr(t_check *c);
void			sab(int *stack, int len_stack, int ssab);
void			ss(t_check *c);
void			rab(int *stack, int len_stack, int rrab);
void			rr_action(t_check *c);
int				pb(t_check *c);
int				pa(t_check *c);

int				*sort_array(int *unsorted, int len);
int				find_median(int *sorted, int len, t_ps *ps);

void			case_two(int *stack, int n, int ab);
void			case_three(int *stack, int n, int ab);
void			case_six(t_check *c, int n);
void			case_big(t_check *c, int n);
void			sort_part(t_check *c, int n, t_big *b);

int				find_max(int *stack, int n);
int				find_min(int *stack, int n);
void			find_pivots(int *sorted, int len, t_big *b);
void			min_or_max_big(int len, t_big *b);
void			min_or_max_big2(int len, t_big *b, int min_dist, int max_dist);

#endif
