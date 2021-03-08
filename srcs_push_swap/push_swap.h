#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define EXAMPLE 0
#include "../shared.h"

typedef struct		s_ps
{
	int				i;
	int				j;
	int				min;
	int				max;
	int				median;
	int				median_value;
	int				dist;
	int				min_dist;
	int				max_dist;
	int				search;
	int				direction;
	int				flag_minmax;
	int				smalls;
	int				bigs;
}					t_ps;

void	rrab(int *stack, int len_stack, int rrrab);
void	rrr(t_check *c);
void	sab(int *stack, int len_stack, int ssab);
void	ss(t_check *c);
void	rab(int *stack, int len_stack, int rrab);
void	rr_action(t_check *c);
int		pb(t_check *c);
int		pa(t_check *c);

int		*sort_array(int *unsorted, int len);
int		find_median(int *sorted, int len, t_ps *ps);

void	case_three(int *stack, int n, int ab);
void	r_case_three(int *stack, int n, int ab);
void	case_six(t_check *c, int n);
void	case_hundred(t_check *c, int n);

#endif