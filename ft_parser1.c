/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:53:17 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/14 17:03:34 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parser_char(va_list arg, int *total_write)
{
	long long	i;

	i = va_arg(arg, int);
	if (ft_putchar(i) == -1)
		return (-1);
	*total_write += 1;
	return (0);
}

int	ft_parser_integer(va_list arg, int *total_write, char step)
{
	long long	i;

	i = va_arg(arg, int);
	if (i < 0)
	{
		i = i * -1;
		if (ft_putchar('-') == -1)
			return (-1);
		*total_write += 1;
	}
	if (ft_putstr(convert(i, 10, step)) == -1)
		return (-1);
	*total_write += ft_count_numbers(i, 10);
	return (0);
}

int	ft_parser_unsigned_integer(va_list arg, int *total_write, char step)
{
	long long	i;

	i = va_arg(arg, unsigned int);
	if (ft_putstr(convert((unsigned long)i, 10, step)) == -1)
		return (-1);
	*total_write += ft_count_numbers((unsigned long)i, 10);
	return (0);
}

int	ft_parser_octal(va_list arg, int *total_write, char step)
{
	long long	i;

	i = va_arg(arg, unsigned int);
	if (ft_putstr(convert(i, 8, step)) == -1)
		return (-1);
	*total_write += ft_count_numbers(i, 8);
	return (0);
}

int	ft_parser_string(va_list arg, int *total_write)
{
	char			*s;

	s = va_arg(arg, char *);
	if (ft_putstr(s) == -1)
		return (-1);
	*total_write += ft_strlen(s);
	if (!s)
		*total_write += ft_strlen("(null)");
	return (0);
}
