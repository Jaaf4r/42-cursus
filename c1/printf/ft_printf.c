#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		n;

	if (!format)
		return (-1);
	n = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break ;
			if (*format == '%')
				n += write(1, "%", 1);
			else
				n += ft_formats(*format, args);
		}
		else
			n += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (n);
}

int	main()
{
	ft_printf("1ST TEST:\n");
	int l1 = printf("- alo %s 3alaykom, %% lyom %d f shher %i li howa %covember \n", "salamo", 9, 9, 'N');
	int l2 = ft_printf("- alo %s 3alaykom, %% lyom %d f shher %i li howa %covember \n", "salamo", 9, 9, 'N');
	ft_printf("+ length --> OG : %d | --> Mine : %d | %s\n\n", l1, l2, (l1 == l2) ? "OK" : "KO");

	ft_printf("2ND TEST:\n");
	int l3 = ft_printf("-wash %s, 7na f %p fl memory\n", "a dyalna", "a dyalna");
	int l4 = printf("-wash %s, 7na f %p fl memory\n", "a dyalna", "a dyalna");
	ft_printf("+ length --> OG : %d | --> Mine : %d | %s\n\n", l3, l4, (l3 == l4) ? "OK" : "KO");

	ft_printf("3RD TEST:\n");
	int l5 = ft_printf("-hexa d 99999999 howa: %x lowercase | %X uppercase\n", 99999999, 99999999);
	int l6 = printf("-hexa d 99999999 howa: %x lowercase | %X uppercase\n", 99999999, 99999999);
	ft_printf("+ length --> OG : %d | --> Mine : %d | %s\n\n", l5, l6, (l5 == l6) ? "OK" : "KO");

	ft_printf("4TH TEST:\n");
	int l7 = ft_printf("-number [-24] unsigned int howa: [%u]\n", 24);
	int l8 = printf("-number [-24] unsigned int howa: [%u]\n", 24);
	ft_printf("+ length --> OG : %d | --> Mine : %d | %s\n\n", l7, l8, (l7 == l8) ? "OK" : "KO");

	ft_printf("5TH TEST:\n");
	char	*s = "skill issue\n";
	int l9 = ft_printf("-%s", s);
	int l10 = printf("-%s", s);
	ft_printf("+ length --> OG : %d | --> Mine : %d | %s\n\n", l9, l10, (l9 == l10) ? "OK" : "KO");

	ft_printf("6TH TEST:\n");
	int l11 = ft_printf("a\n");
	int l12 = printf("a\n");
	ft_printf("+ length --> OG : %d | --> Mine : %d | %s\n\n", l11, l12, (l11 == l12) ? "OK" : "KO");

	ft_printf("7TH TEST:\n");
	int l13 = ft_printf("%");
	int l14 = printf("%");
	ft_printf("+ length --> OG : %d | --> Mine : %d | %s\n\n", l13, l14, (l13 == l14) ? "OK" : "KO");
}
