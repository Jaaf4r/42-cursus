/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:11:09 by jabouhni          #+#    #+#             */
/*   Updated: 2024/11/10 22:11:22 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

int	ft_char(int c);
int	ft_str(char *s);
int	ft_digit(long n, int base, int uplowcase);
int	handle_format(char format, va_list args);
int	process_format(const char **format, va_list args);
int	ft_printf(const char *format, ...);

#endif