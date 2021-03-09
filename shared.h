#ifndef SHARED_H
# define SHARED_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct	s_check
{
	int			init_len_a;
	int			*stack_a;
	int			*stack_b;
	int			len_a;
	int			len_b;
}				t_check;

int		count_args(char **argv);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(char *str);
int		ft_isdigit(int c);
int		get_next_line(int fd, char **line);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
int		check_doubles(int *stack);
int		check_if_number(char *s);
void	ft_exit(char *msg, int a);
int		*malloc_and_fill(int size);
int		init_struct(t_check *c, int argc, char **argv);
void	print_stack(t_check *c);
int		*get_stack(int argc, char **argv);
int		*sort_array(int *unsorted, int len);
long long				ft_atoll(char *str);


#endif