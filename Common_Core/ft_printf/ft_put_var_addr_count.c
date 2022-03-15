/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_var_addr_count.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:22:12 by afaris            #+#    #+#             */
/*   Updated: 2021/12/05 12:50:39 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_put_x(unsigned long n, int *res)
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
		ft_put_x(n / 16, res);
		ft_put_x(n % 16, res);
	}
}

int	ft_put_var_addr_count(unsigned long p)
{
	int	len;

	len = 0;
	write(1, "0x", 2);
	len += 2;
	ft_put_x(p, &len);
	return (len);
}
