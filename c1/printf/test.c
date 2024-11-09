#include <stdarg.h>
#include <stdio.h>

void sum(int t, ...)
{
	va_list	ap;

	va_start(ap, t);
	if (t == 1)
		printf("%d\n", va_arg(ap, int));
	else if (t == 2)
		printf("%c\n", va_arg(ap, int));
	else
		printf("%s\n", va_arg(ap, char *));
	va_end(ap);
}

int	main()
{
	sum(1, 99);
	sum(2, (char)'A');
	sum(5, "salam");
}