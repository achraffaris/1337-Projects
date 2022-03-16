/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:12:53 by afaris            #+#    #+#             */
/*   Updated: 2021/12/04 17:54:54 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_put_lowx(unsigned int n, int *res)
{
	char	*base_16;

	base_16 = "0123456789abcdef";
	if (n < 16)
	{
		ft_putchar(base_16[n]);
		*res += 1;
	}
	else
	{
		ft_put_lowx(n / 16, res);
		ft_put_lowx(n % 16, res);
	}
}

static	void	ft_put_upx(unsigned int n, int*res)
{
	char	*base_16;

	base_16 = "0123456789ABCDEF";
	if (n < 16)
	{
		ft_putchar(base_16[n]);
		*res += 1;
	}
	else
	{
		ft_put_upx(n / 16, res);
		ft_put_upx(n % 16, res);
	}
}

int	ft_put_hex_count(unsigned int n, char flag)
{
	int	len;

	len = 0;
	if (flag == 'x')
		ft_put_lowx(n, &len);
	else if (flag == 'X')
		ft_put_upx(n, &len);
	return (len);
}
