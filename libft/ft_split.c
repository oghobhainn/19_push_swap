/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:36:22 by cmcgahan          #+#    #+#             */
/*   Updated: 2019/10/24 14:41:15 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			**ft_free(char **str, int len)
{
	while (len > 0)
	{
		free(str[len]);
		str[len] = NULL;
		len--;
	}
	free(str);
	str = NULL;
	return (NULL);
}

static int			ft_count_words(const char *str, char c)
{
	unsigned int	i;
	int				count;

	if (!str)
		return (0);
	i = 0;
	count = (str[i] == '\0') ? 0 : 1;
	while (str[i] && str[i] == c)
		i++;
	if (i == ft_strlen(str))
		return (0);
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			count += 1;
		i++;
	}
	return (count);
}

char				**ft_split(char const *s, char c)
{
	char			**strsplit;
	unsigned int	i;
	int				j;
	size_t			len;

	j = ft_count_words(s, c);
	if (s == NULL || !(strsplit = (char **)malloc(sizeof(char *) * j + 1)))
		return (NULL);
	strsplit[j] = NULL;
	i = 0;
	j = -1;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		len = 0;
		while (s[i] && s[i] != c && ++len > 0)
			i++;
		if (len == 0)
			break ;
		if (++j >= 0 && !(strsplit[j] = ft_substr(s, i - len, len)))
			return (ft_free(strsplit, j));
	}
	return (strsplit);
}
