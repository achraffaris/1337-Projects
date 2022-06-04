#include "../push_swap.h"

int is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int is_sign(char c)
{
	return (c == '+' || c == '-');
}

int is_max(t_stack s, int n)
{
	int i;

	i = 0;
	while (i < s.size)
	{
		if (n < s.arr[i])
			return (0);
		i++;
	}
	return (1);
}

int is_min(t_stack s, int n)
{
	int i;

	i = 0;
	while (i < s.size)
	{
		if (n > s.arr[i])
			return (0);
		i++;
	}
	return (1);
}

int is_sorted(t_stack s)
{
    int i;

    i = 0;
    while (i < s.size)
    {
        if (s.arr[i] < s.arr[i + 1])
            return (0);
        i++;
    }
    return (1);
}
