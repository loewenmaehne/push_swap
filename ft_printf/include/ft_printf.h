/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:58:37 by jzienert          #+#    #+#             */
/*   Updated: 2025/08/21 18:13:17 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h> 
# include <limits.h>

int		ft_printf(const char *input, ...);
char	*ft_uitoa(unsigned int n);
char	*ft_malnumlen(long n);
ssize_t	ft_printf_handle_s(va_list args);
ssize_t	ft_printf_handle_c(va_list args);
ssize_t	ft_printf_handle_p(va_list args);
ssize_t	ft_printf_handle_di(va_list args);
ssize_t	ft_printf_handle_u(va_list args);
ssize_t	ft_printf_handle_x(va_list args, int touppercase);
char	*ft_p_to_hex(uintptr_t num, int isuppercase);
char	*ft_ui_to_hex(unsigned int num, int isuppercase);
ssize_t	ft_free_on_error(char *s);
char	*ft_free_strrev(char *s);
#endif