/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 01:12:34 by jzienert          #+#    #+#             */
/*   Updated: 2025/08/07 13:31:14 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/**
 * @brief Malloc space for hex conversion using number (uintptr_t)
 * 
 * @param n [in] Pointer value as a number (uintptr_t).
 * @return char * New malloced string.
 *
 * @note Caller must free().
 * @warning 42 student
 * @see ft_p_to_hex() ft_ui_to_hex()
 */
static char	*ft_uipmalnumlen(uintptr_t n)
{
	ssize_t			count;
	uintptr_t		temp;
	char			*chrp;

	temp = n;
	count = 0;
	if (temp == 0)
		count++;
	while (temp != 0)
	{
		temp = temp / 16;
		count++;
	}
	chrp = malloc(count + 1);
	if (!chrp)
		return (NULL);
	return (chrp);
}

/**
 * @brief Helper function for choosing hexadecimal set for lower or uppercase
 * 
 * @param touppercase [in] Hex conversion output in uppercase letters. (1/0)
 * @return char * String hexadecimal set in lower or uppercase.
 *
 * @warning 42 student
 * @see ft_p_to_hex() ft_ui_to_hex()
 */
static const char	*ft_set_of_hex(int touppercase)
{
	if (touppercase)
		return ("0123456789ABCDEF");
	else
		return ("0123456789abcdef");
}

/**
 * @brief Convert pointer as uintptr_t to hexadecimal (base 16)
 * 
 * @param num [in] Pointer to convert as number (uintptr_t).
 * @param touppercase [in] Hex conversion output in uppercase letters. (1/0)
 * @return char * String in hexadecimal format in lowercase or uppercase letters.
 *
 * @note Caller must free().
 * @warning 42 student
 * @see ft_printf_handle_p()
 */
char	*ft_p_to_hex(uintptr_t num, int touppercase)
{
	const char	*hex;
	char		*tmp;
	char		*result;
	size_t		i;

	hex = ft_set_of_hex(touppercase);
	i = 0;
	tmp = ft_uipmalnumlen(num);
	if (!tmp)
		return (NULL);
	if (num == 0)
		tmp[i++] = '0';
	while (num > 0)
	{
		tmp[i] = hex[num % 16];
		num = num / 16;
		i++;
	}
	tmp[i] = '\0';
	result = ft_free_strrev(tmp);
	return (result);
}

/**
 * @brief Convert an unsigned int to hexadecimal (base 16)
 * 
 * @param num [in] Number to convert (unsigned int).
 * @param touppercase [in] Hex conversion output in uppercase letters. (1/0)
 * @return char * String in hexadecimal in lowercase or uppercase letters.
 *
 * @note Caller must free().
 * @warning 42 student
 * @see ft_printf_handle_x()
 */
char	*ft_ui_to_hex(unsigned int num, int touppercase)
{
	const char	*hex;
	char		*tmp;
	char		*result;
	size_t		i;

	hex = ft_set_of_hex(touppercase);
	i = 0;
	tmp = ft_malnumlen((unsigned long) num);
	if (!tmp)
		return (NULL);
	if (num == 0)
		tmp[i++] = '0';
	while (num > 0)
	{
		tmp[i] = hex[num % 16];
		num = num / 16;
		i++;
	}
	tmp[i] = '\0';
	result = ft_free_strrev(tmp);
	return (result);
}
