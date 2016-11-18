/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:27:16 by mkantzer          #+#    #+#             */
/*   Updated: 2016/11/07 12:39:55 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long nl;

	nl = n;
	if (nl < 0)
	{
		ft_putchar('-');
		nl = nl * -1;
	}
	if (nl >= 10)
		ft_putnbr(nl / 10);
	ft_putchar((nl % 10) + 48);
}