/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:11:09 by jabouhni          #+#    #+#             */
/*   Updated: 2024/11/12 23:00:56 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

int		ft_char(int c);
int		ft_str(char *s);
int		ft_signed(long n);
int		ft_hex(long n, int base, int uppcase);
int	ft_digit(unsigned long n, int base, int uplowcase, int is_signed);
int		handle_format(char format, va_list args);
int		process_format(const char **format, va_list args);
int		ft_printf(const char *format, ...);
int		ft_length(int n);
char	*ft_itoa(int n);

#endif