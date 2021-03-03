/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmcgahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:56:00 by cmcgahan          #+#    #+#             */
/*   Updated: 2019/10/23 14:11:21 by cmcgahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_len(int n)
{
	int		len;

	len = (n < 0) ? 1 : 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	int		sign;
	long	nbr;
	char	*ans;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nbr = (long)n;
	sign = (nbr < 0) ? -1 : 0;
	len = nbr_len(nbr);
	nbr = (sign == -1) ? -nbr : nbr;
	if (!(ans = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (sign == -1)
		ans[0] = '-';
	ans[len] = '\0';
	while (len-- > 0 - sign)
	{
		ans[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (ans);
}
