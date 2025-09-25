/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 01:05:47 by jzienert          #+#    #+#             */
/*   Updated: 2025/08/07 13:39:14 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../../libft/include/libft.h"

/**
 * @brief Free malloced string on error and return -1
 * 
 * @param s [in, out] Free malloced string.
 * @return ssize_t Returns -1 because an error occured.
 * 
 * @note Gets called in error cases, where the malloced string must be freed.
 * @warning 42 student
 * @see ft_printf_write_specifier() ft_handle_input()
 */
ssize_t	ft_free_on_error(char *s)
{
	free(s);
	return (-1);
}

/**
 * @brief Convert and write out next number %x (unsigned int) in hexadecimal
 * 
 * @param args [in, out] Take initialized va_list for next unsigned int.
 * @param touppercase [in] Hex conversion output in uppercase letters. (1/0)
 * @return ssize_t Number of bytes written to output or -1 on error.
 * 
 * @note va_arg() iterates arg one position further globally.
 * @warning 42 student
 * @see ft_printf_write_specifier() ft_handle_input()
 */
ssize_t	ft_printf_handle_x(va_list args, int touppercase)
{
	int		num;
	char	*s;
	ssize_t	slen;
	ssize_t	w_bytes;

	num = va_arg(args, unsigned int);
	s = ft_ui_to_hex(num, touppercase);
	if (!s)
		return (-1);
	slen = ft_strlen(s);
	w_bytes = write(1, s, slen);
	free(s);
	return (w_bytes);
}
