/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_and_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:00:36 by cmcgahan          #+#    #+#             */
/*   Updated: 2021/03/11 15:00:38 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			get_flags(char *flags, t_check *c)
{
	int			i;

	i = 1;
	while (flags[i])
	{
		if (flags[i] == 'v')
			c->flag_v = 1;
		else if (flags[i] == 'c')
			c->flag_c = 1;
		else
			return ;
		i++;
	}
}

char			**args_and_flags2(char **argv, t_check *c)
{
	char		**args;

	if (argv[1][0] == '-')
	{
		get_flags(argv[1], c);
		args = argv + 2;
	}
	else
		args = argv + 1;
	return (args);
}

char			**args_and_flags(int argc, char **argv, t_check *c)
{
	char		**args;

	args = NULL;
	if (argc < 2)
		ft_exit("Error: No args\n", 2);
	else if (argc == 2)
	{
		if (!(args = ft_split(argv[1], ' ')))
			ft_exit("Error: split malloc\n", 2);
	}
	else if (argc == 3)
	{
		if (argv[1][0] == '-')
		{
			get_flags(argv[1], c);
			if (!(args = ft_split(argv[2], ' ')))
				ft_exit("Error: split malloc\n", 2);
		}
		else
			args = argv + 1;
	}
	else
		args = args_and_flags2(argv, c);
	return (args);
}
