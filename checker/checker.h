#ifndef CHECKER_H
# define CHECKER_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct	s_check
{
	int			*stack_a;
	int			*stack_b;
	int			stack_len;
	int			nb_elem_a;
	int			nb_elem_b;
}				t_check;

void	print_stack(int *stack_a, int *stack_b, int len_stack);
int		check_doubles(int *stack);
int		check_if_number(char *s);
int		*get_stack(int argc, char **argv);
int		check_if_sorted(int *stack_a, int len_stack);
int		is_valid(char *s);
void	ft_exit(char *msg, int a);
int		*malloc_and_fill(int size);
void	use_action(int *stack_a, int *stack_b, int len_stack, char *action);
void	sab_action(int *stack, int len_stack);
void	ss_action(int *stack_a, int *stack_b, int len_stack);
void	rab_action(int *stack, int len_stack);
void	rr_action(int *stack_a, int *stack_b, int len_stack);
void	rrab_action(int *stack, int len_stack);
void	rrr_action(int *stack_a, int *stack_b, int len_stack);








/*
** UTILS
*/

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(char *str);
int		ft_isdigit(int c);
int		get_next_line(int fd, char **line);
int		ft_strcmp(const char *s1, const char *s2);






#endif