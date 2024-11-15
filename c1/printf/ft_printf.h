/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:04:28 by jabouhni          #+#    #+#             */
/*   Updated: 2024/11/15 22:54:25 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

int	ft_char(int c);
int	ft_str(char *s);
int	ft_digit(unsigned long n, int base, int uplowcase, int is_signed);
int	handle_format(char format, va_list args);
int	process_format(const char **format, va_list args);
int	ft_printf(const char *format, ...);

#endif