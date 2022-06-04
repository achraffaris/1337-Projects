#include "../push_swap.h"

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
	if (is_sign(nptr[i]) && is_number(nptr[i + 1]))
	{
		if (nptr[i] == '-')
			s = -1;
		i++;
	}
	while (nptr[i])
	{
		if (!is_number(nptr[i]) || valid_interger(res, s))
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



t_stack clean_data(char **av, int ac)
{
    int n;
    int i;
    t_stack s;

    s.size = ac - 1;
    s.arr = malloc(sizeof(int) * (s.size));
    s.top = s.size - 1;
    if (!s.arr)
        raise_error();
    n = s.size - 1;
    i = 1;
    if (!duplicated_args(av, ac))
    {
        while (i <= s.size && av[i])
        {
            s.arr[n] = ft_atoi(av[i]);
            i++;
            n--;
        }
    }
    else
        raise_error();
    if (is_sorted(s))
        raise_error();
    return (s);
}