/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:53:17 by imurugar          #+#    #+#             */
/*   Updated: 2022/09/21 14:53:18 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parser_char(va_list arg, int *total_write)
{
	long long	i;

	i = va_arg(arg, int);
	ft_putchar(i);
	*total_write += 1;
}

void	ft_parser_integer(va_list arg, int *total_write, char step)
{
	long long	i;

	i = va_arg(arg, int);
	if (i < 0)
	{
		i = i * -1;
		ft_putchar('-');
		*total_write += 1;
	}
	ft_putstr(convert(i, 10, step));
	*total_write += ft_count_numbers(i, 10);
}

void	ft_parser_unsigned_integer(va_list arg, int *total_write, char step)
{
	long long	i;

	i = va_arg(arg, unsigned int);
	ft_putstr(convert((unsigned long)i, 10, step));
	*total_write += ft_count_numbers((unsigned long)i, 10);
}

void	ft_parser_octal(va_list arg, int *total_write, char step)
{
	long long	i;

	i = va_arg(arg, unsigned int);
	ft_putstr(convert(i, 8, step));
	*total_write += ft_count_numbers(i, 8);
}

void	ft_parser_string(va_list arg, int *total_write)
{
	char			*s;

	s = va_arg(arg, char *);
	ft_putstr(s);
	*total_write += ft_strlen(s);
	if (!s)
		*total_write += ft_strlen("(null)");
}
