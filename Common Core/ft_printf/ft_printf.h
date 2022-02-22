/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:31:05 by afaris            #+#    #+#             */
/*   Updated: 2021/12/05 13:59:23 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void			ft_putchar(char c);
int				ft_put_str_count(char *s);
int				ft_put_int_count(int n, char flag);
int				ft_put_uns_int_count(unsigned int nb);
int				ft_put_percent_count(void);
int				ft_printf(const char *str, ...);
int				ft_put_hex_count(unsigned int n, char flag);
int				ft_put_var_addr_count(unsigned long p);

#endif