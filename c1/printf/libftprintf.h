#ifndef LIBFTPRINTF
# define LIBFTPRINTF

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int		ft_printf(const char *format, ...);
int     ft_formats(char format, va_list args);

#endif