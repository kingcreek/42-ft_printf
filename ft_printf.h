/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:53:31 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/14 16:58:58 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>

int		ft_printf(const char *str, ...);
char	*convert(unsigned long long num, int base, char cmd);
int		ft_count_numbers(unsigned long long number, int base);
int		ft_putchar(char c);
int		ft_putstr(char *s);
size_t	ft_strlen(const char *str);
int		ft_parser_hexadecimal(va_list arg, int *total_write, char step);
int		ft_parser_pointer(va_list arg, int *total_write, char step);
int		ft_parser_char(va_list arg, int *total_write);
int		ft_parser_integer(va_list arg, int *total_write, char step);
int		ft_parser_unsigned_integer(va_list arg, int *total_write, char step);
int		ft_parser_octal(va_list arg, int *total_write, char step);
int		ft_parser_string(va_list arg, int *total_write);

#endif