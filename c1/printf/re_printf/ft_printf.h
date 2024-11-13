#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_char(char c);
int	ft_str(char *s);
int	ft_digit(unsigned long n, int base, int uppcase, int is_signed);
int	handle_format(char format, va_list args);
int	process_format(const char **format, va_list args);
int	ft_printf(const char *, ...);

#endif