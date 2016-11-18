/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:50:54 by mkantzer          #+#    #+#             */
/*   Updated: 2016/11/12 17:15:50 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_print(int n, int size, char *str, int i)
{
	while (n >= 10)
	{
		str[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	if (n < 10)
		str[i] = n + 48;
	str[size + 1] = '\0';
	return (str);
}

static int		ft_size(int size, int i)
{
	while (i >= 10)
	{
		i = i / 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		i;
	int		neg;

	str = NULL;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = 0;
	neg = 0;
	if (n < 0)
	{
		n = n * -1;
		size++;
		neg = 1;
	}
	size = ft_size(size, n);
	i = size;
	str = (char *)malloc((size + 2) * sizeof(char));
	if (str == 0)
		return (NULL);
	if (neg)
		str[0] = '-';
	return (ft_print(n, size, str, i));
}
