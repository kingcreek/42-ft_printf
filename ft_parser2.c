/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:53:22 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/14 17:12:30 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parser_hexadecimal(va_list arg, int *total_write, char step)
{
	long long	i;

	i = va_arg(arg, unsigned int);
	if (ft_putstr(convert(i, 16, step)) == -1)
		return (-1);
	*total_write += ft_count_numbers(i, 16);
	return (0);
}

int	ft_parser_pointer(va_list arg, int *total_write, char step)
{
	long long	i;

	i = (unsigned long long)va_arg(arg, void *);
	if (ft_putstr("0x") == -1)
		return (-1);
	if (ft_putstr(convert(i, 16, step)) == -1)
		return (-1);
	*total_write += ft_count_numbers(i, 16) + 2;
	return (1);
}
