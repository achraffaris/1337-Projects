/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:32:37 by afaris            #+#    #+#             */
/*   Updated: 2021/12/05 13:34:32 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	is_flag(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static	int	handle_flags(va_list args, char flag)
{
	if (flag == 's')
		return (ft_put_str_count(va_arg(args, char *)));
	else if (flag == 'i' || flag == 'd' || flag == 'c')
		return (ft_put_int_count(va_arg(args, int), flag));
	else if (flag == 'u')
		return (ft_put_uns_int_count(va_arg(args, unsigned int)));
	else if (flag == 'p')
		return (ft_put_var_addr_count(va_arg(args, unsigned long)));
	else if (flag == 'x' || flag == 'X')
		return (ft_put_hex_count(va_arg(args, unsigned int), flag));
	else if (flag == '%')
		return (ft_put_percent_count());
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	l;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start(l, str);
	while (str[i])
	{
		if ((str[i] == '%' && is_flag(str[i + 1])))
		{
			len += handle_flags(l, str[i + 1]);
			i += 2;
			len -= 2;
		}
		else
			write(1, &str[i++], 1);
	}
	va_end(l);
	return (i + len);
}
