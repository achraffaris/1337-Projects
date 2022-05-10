/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:51:20 by afaris            #+#    #+#             */
/*   Updated: 2022/05/10 12:58:45 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    raise_error()
{
    write(2, "Error\n", 7);
    exit(1);
}

int valid_interger(long long res, int s)
{
    if (res > INT_MAX && s == 1)
		raise_error();
	else if (res > INT_MIN && s == -1)
		raise_error();
    return (res * s);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	long long	res;
	int	s;

	s = 1;
	res = 0;
	i = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s = -1;
		i++;
	}
	while (nptr[i])
	{
		if (nptr[i] < '0' || nptr[i] > '9')
        	raise_error();
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (valid_interger(res, s));
}

int duplicated_args(char **av, int ac)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (i < ac)
    {
        j = i + 1;
        while (j < ac)
        {
            if (ft_strcmp(av[i], av[j]) == 0)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int *clean_data(char **av, int ac)
{
    int n;
    int i;
    int *arr;

    arr = malloc(sizeof(int) * (ac));
    n = 0;
    i = 1;
    if (!duplicated_args(av, ac))
    {
        while (i < ac && av[i])
        {
            arr[n] = ft_atoi(av[i]);
            i++;
            n++;
        }
    }
    else
        raise_error();
    return (arr);
}