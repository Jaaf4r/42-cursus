#ifndef LIBFTPRINTF
# define LIBFTPRINTF

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int		ft_printf(const char *format, ...);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);


#endif