/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:38:14 by jzienert          #+#    #+#             */
/*   Updated: 2025/08/07 13:36:30 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../../libft/include/libft.h"

/**
 * @brief Write out next string %s (char *)
 * 
 * @param args [in, out] Take initialized va_list for next char *.
 * @return ssize_t write() Number of bytes written to output or -1 on error.
 * 
 * @note va_arg() iterates arg one position further globally.
 * @note Writes out "(null)" when NULL.
 * @warning 42 student
 * @see ft_printf_write_specifier() ft_handle_input()
 */
ssize_t	ft_printf_handle_s(va_list args)
{
	char	*s;
	ssize_t	slen;

	s = va_arg(args, char *);
	if (!s)
		return (write(1, "(null)", 6));
	slen = ft_strlen(s);
	return (write(1, s, slen));
}

/**
 * @brief Write out next character %c (int)
 * 
 * @param args [in, out] Take initialized va_list for next int.
 * @return ssize_t write() Number of bytes written to output (1) or -1 on error.
 * 
 * @note va_arg() iterates arg one position further globally.
 * @warning 42 student
 * @see ft_printf_write_specifier() ft_handle_input()
 */
ssize_t	ft_printf_handle_c(va_list args)
{
	char	c;

	c = (char) va_arg(args, int);
	return (write(1, &c, 1));
}

/**
 * @brief Write out next pointer %p (void *)
 * 
 * @param args [in, out] Take initialized va_list for next void *.
 * @return ssize_t write() Number of bytes written to output or -1 on error.
 *
 * @note va_arg() iterates arg one position further globally.
 * @note Writes out "(nil)" on NULL pointer.
 * @warning 42 student
 * @see ft_printf_write_specifier() ft_handle_input()
 */
ssize_t	ft_printf_handle_p(va_list args)
{
	void	*ptr;
	char	*s;
	ssize_t	slen;
	ssize_t	w_bytes;

	ptr = va_arg(args, void *);
	if (!ptr)
		return (write(1, "(nil)", 5));
	else
	{
		s = ft_p_to_hex((uintptr_t) ptr, 0);
		if (!s)
			return (-1);
		slen = ft_strlen(s);
		w_bytes = write(1, "0x", 2);
		if (w_bytes == -1)
			return (ft_free_on_error(s));
		w_bytes = write(1, s, slen);
		if (w_bytes == -1)
			return (ft_free_on_error(s));
		w_bytes += 2;
	}
	free(s);
	return (w_bytes);
}

/**
 * @brief Write out next decimal %d or integer %i (int)
 * 
 * @param args [in, out] Take initialized va_list for next int.
 * @return ssize_t write() Number of bytes written to output or -1 on error.
 *
 * 
 * @note va_arg() iterates arg one position further globally.
 * @warning 42 student
 * @see ft_printf_write_specifier() ft_handle_input()
 */
ssize_t	ft_printf_handle_di(va_list args)
{
	ssize_t	num;
	char	*s;
	ssize_t	slen;
	ssize_t	w_bytes;

	num = va_arg(args, int);
	s = ft_itoa(num);
	if (!s)
		return (-1);
	slen = ft_strlen(s);
	w_bytes = write(1, s, slen);
	free(s);
	return (w_bytes);
}

/**
 * @brief Write out next unsigned integer %u (unsigned int)
 * 
 * @param args [in, out] Take initialized va_list for next unsinged int.
 * @return ssize_t write() Number of bytes written to output or -1 on error.
 *
 * 
 * @note va_arg() iterates arg one position further globally.
 * @warning 42 student
 * @see ft_printf_write_specifier() ft_handle_input()
 */
ssize_t	ft_printf_handle_u(va_list args)
{
	unsigned int	num;
	char			*s;
	ssize_t			slen;
	ssize_t			w_bytes;

	num = va_arg(args, unsigned int);
	s = ft_uitoa(num);
	if (!s)
		return (-1);
	slen = ft_strlen(s);
	w_bytes = write(1, s, slen);
	free(s);
	return (w_bytes);
}
