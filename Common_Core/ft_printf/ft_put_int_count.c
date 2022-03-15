/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_int_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:29:04 by afaris            #+#    #+#             */
/*   Updated: 2021/12/05 13:35:05 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(int n)
{
	unsigned int	nb;

	if (n < 0)
	{
		nb = n * -1;
		ft_putchar('-');
	}
	else
		nb = n;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar('0' + nb);
}

static int	ft_decimal_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		n *= -1;
		i++;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_put_int_count(int n, char flag)
{
	if (flag == 'c')
	{
		ft_putchar(n);
		return (1);
	}	
	else if (flag == 'd' || flag == 'i')
	{
		ft_putnbr(n);
		return (ft_decimal_len(n));
	}
	return (0);
}
