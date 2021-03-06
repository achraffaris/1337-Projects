/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:01:52 by afaris            #+#    #+#             */
/*   Updated: 2022/07/03 12:42:28 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (nptr[i])
	{
		if (nptr[i] <= '9' && nptr[i] >= '0')
			res = res * 10 + (nptr[i] - '0');
		else
			exit(0);
		i++;
	}
	return (res);
}
