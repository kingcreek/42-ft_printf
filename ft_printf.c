/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:53:27 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/14 17:17:00 by imurugar         ###   ########.fr       */
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

int	ft_parse_arg(char step, va_list arg, int *total_write)
{
	if (step == 'c')
		return (ft_parser_char(arg, total_write));
	else if (step == 'd' || step == 'i')
		return (ft_parser_integer(arg, total_write, step));
	else if (step == 'u')
		return (ft_parser_unsigned_integer(arg, total_write, step));
	else if (step == 'o')
		return (ft_parser_octal(arg, total_write, step));
	else if (step == 's')
		return (ft_parser_string(arg, total_write));
	else if (step == 'x' || step == 'X')
		return (ft_parser_hexadecimal(arg, total_write, step));
	else if (step == 'p')
		return (ft_parser_pointer(arg, total_write, step));
	else
	{
		*total_write += 1;
		return (ft_putchar(step));
	}
}

int	ft_printf(const char *str, ...)
{
	int				total_write;
	va_list			arg;

	total_write = 0;
	va_start(arg, str);
	while (*str != '\0')
	{
		while (*str != '%')
		{
			if (*str == '\0')
				return (va_end(arg), total_write);
			if (ft_putchar(*str) == -1)
				return (-1);
			str++;
			total_write++;
		}
		str++;
		if (ft_parse_arg(*str, arg, &total_write) == -1)
			return (-1);
		if (*str == '\0')
			return (total_write);
		str++;
	}
	va_end(arg);
	return (total_write);
}
