/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:44:32 by afaris            #+#    #+#             */
/*   Updated: 2022/05/21 15:00:44 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

int	len_count(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*end_with(char *str, char *end)
{
	int	strlen;
	int	endlen;
	int	i;

	i = 0;
	strlen = len_count(str);
	endlen = len_count(end);
	while (endlen)
	{
		if (str[strlen--] != end[endlen--])
			raise_error("Invalid File Format!\n");
	}
	return (str);
}

int	exists(t_map m, char c, int many)
{
	int	i;
	int	j;
	int	f;

	i = 0;
	j = 0;
	f = 0;
	while (m.map[i])
	{
		while (m.map[i][j])
		{
			if (m.map[i][j] == c)
				f++;
			j++;
		}
		j = 0;
		i++;
	}
	if ((!many && f > 1) || f == 0)
		return (0);
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
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
