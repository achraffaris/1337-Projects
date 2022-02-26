 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uns_int_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:13:04 by afaris            #+#    #+#             */
/*   Updated: 2021/12/05 13:35:36 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_uns_int(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_put_uns_int(nb / 10);
		ft_put_uns_int(nb % 10);
	}
	else
		ft_putchar('0' + nb);
}

static int	ft_uns_int_count(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int	ft_put_uns_int_count(unsigned int nb)
{
	ft_put_uns_int(nb);
	return (ft_uns_int_count(nb));
}
