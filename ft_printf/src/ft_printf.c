/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:38:32 by jzienert          #+#    #+#             */
/*   Updated: 2025/08/07 13:31:14 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/**
 * @brief Write unkown format specifier as is.
 * 
 * @param c [in] Unkown format specifier character
 * @return ssize_t Bytes succesfully written or -1 on error.
 *
 * @note Format specifiers in ft_printf str:(%s, %p, %d, %i, %u, %x, %X, %%)
 * @warning 42 student
 * @see ft_printf_write_specifier()
 */
static ssize_t	ft_write_unkown_specifier(char c)
{
	ssize_t	w_bytes;

	w_bytes = write(1, "%", 1);
	if (w_bytes == -1)
		return (w_bytes);
	w_bytes = write(1, &c, 1);
	if (w_bytes == -1)
		return (w_bytes);
	return (2);
}

/**
 * @brief Check format specifier and calls converting function for output.
 * 
 * @param c [in] Format specifier character
 * @param args [in, out] Forward initialized va_list to corresponding function
 * @return ssize_t Bytes succesfully written or -1 on error.
 *
 * @note Format specifiers in ft_printf str:(%s, %p, %d, %i, %u, %x, %X, %%)
 * @warning 42 student
 * @see ft_handle_input()
 */
static ssize_t	ft_printf_write_specifier(char c, va_list args)
{
	if (c == ('c'))
		return (ft_printf_handle_c(args));
	else if (c == ('s'))
		return (ft_printf_handle_s(args));
	else if (c == ('p'))
		return (ft_printf_handle_p(args));
	else if (c == ('d') || c == ('i'))
		return (ft_printf_handle_di(args));
	else if (c == ('u'))
		return (ft_printf_handle_u(args));
	else if (c == ('x'))
		return (ft_printf_handle_x(args, 0));
	else if (c == ('X'))
		return (ft_printf_handle_x(args, 1));
	else if (c == ('%'))
		return (write(1, "%", 1));
	else
		return (ft_write_unkown_specifier(c));
}

/**
 * @brief Check if format specifier applies at pos i else write current char
 * 
 * @param input [in] Input string with possible format specifiers.
 * @param args [in, out] Forward an initialized va_list for correct iteration.
 * @return ssize_t Bytes successfully written or -1 on error.
 *
 * @note Format specifiers in ft_printf str:(%s, %p, %d, %i, %u, %x, %X, %%)
 * @note If format specifier applies call func to determine, convert and write.
 * @warning 42 student
 * @see ft_printf_write_specifier()
 */
static ssize_t	ft_handle_input_at(const char *input, va_list args, ssize_t *i)
{
	ssize_t	w_bytes;
	ssize_t	tmp;

	tmp = *i;
	if (input[tmp] == '%' && input[tmp + 1])
	{
		w_bytes = ft_printf_write_specifier(input[tmp + 1], args);
		(*i)++;
	}
	else
		w_bytes = write(1, &input[tmp], 1);
	(*i)++;
	return (w_bytes);
}

/**
 * @brief Print a string and variable args through format specifiers. 
 * 
 * @param input [in] Input string with possible format specifiers.
 * @param ... [in] Variable arguments to match format specifiers in input
 * @return int Total length of output string. -1 on Error.
 *
 * @note Format specifiers in ft_printf str:(%s, %p, %d, %i, %u, %x, %X, %%)
 * @warning 42 student
 * @see ft_handle_input()
 */
int	ft_printf(const char *input, ...)
{
	va_list	args;
	ssize_t	i;
	ssize_t	len;
	ssize_t	w_bytes;

	i = 0;
	len = 0;
	va_start(args, input);
	while (input[i])
	{
		w_bytes = ft_handle_input_at(input, args, &i);
		if (w_bytes == -1)
		{
			len = -1;
			break ;
		}
		len += w_bytes;
	}
	va_end(args);
	if (len > INT_MAX)
		return (-1);
	return ((int) len);
}
