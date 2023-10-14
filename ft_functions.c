/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:53:12 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/14 17:12:46 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_numbers(unsigned long long number, int base)
{
	int		count;

	count = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number = number / base;
		count++;
	}
	return (count);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	if (!s)
	{
		return (ft_putstr("(null)"));
	}
	while (*s)
	{
		if (ft_putchar(*s) == -1)
			return (-1);
		s++;
	}
	return (1);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
