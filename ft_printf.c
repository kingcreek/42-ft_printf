/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:53:27 by imurugar          #+#    #+#             */
/*   Updated: 2023/03/14 18:57:57 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert(unsigned long long num, int base, char cmd)
{
	char		*hex;
	static char	buffer[50];
	char		*ptr;

	hex = "0123456789abcdef";
	if (cmd == 'X')
		hex = "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	if (num == 0)
		*--ptr = hex[num % base];
	while (num != 0)
	{
		*--ptr = hex[num % base];
		num /= base;
	}
	return (ptr);
}

void	ft_parse_arg(char step, va_list arg, int *total_write)
{
	if (step == 'c')
		ft_parser_char(arg, total_write);
	else if (step == 'd' || step == 'i')
		ft_parser_integer(arg, total_write, step);
	else if (step == 'u')
		ft_parser_unsigned_integer(arg, total_write, step);
	else if (step == 'o')
		ft_parser_octal(arg, total_write, step);
	else if (step == 's')
		ft_parser_string(arg, total_write);
	else if (step == 'x' || step == 'X')
		ft_parser_hexadecimal(arg, total_write, step);
	else if (step == 'p')
		ft_parser_pointer(arg, total_write, step);
	else
	{
		ft_putchar(step);
		*total_write += 1;
	}
}

int	ft_printf(const char *str, ...)
{
	int				total_write;
	const char		*step;
	va_list			arg;

	total_write = 0;
	va_start(arg, str);
	step = str;
	while (*step != '\0')
	{
		while (*step != '%')
		{
			if (*step == '\0')
				return (total_write);
			ft_putchar(*step);
			step++;
			total_write++;
		}
		step++;
		ft_parse_arg(*step, arg, &total_write);
		step++;
	}
	va_end(arg);
	return (total_write);
}
