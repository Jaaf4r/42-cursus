#include <stdio.h>
#include <stdarg.h>

void print_value(int type, ...)
{
	va_list args;
	va_start(args, type);  // Initialize va_list

	if (type == 1) // Integer
	{
		int val = va_arg(args, int);
		printf("Integer: %d\n", val);
	}
	else if (type == 2) // Double
	{
		double val = va_arg(args, double);
		printf("Double: %f\n", val);
	}
	else if (type == 3) // String
	{
		char* val = va_arg(args, char*);
		printf("String: %s\n", val);
	}

	va_end(args);  // Clean up
}

int main() {
	print_value(1, 42);              // Output: Integer: 42
	print_value(2, 3.1415);          // Output: Double: 3.1415
	print_value(3, "Hello, world!"); // Output: String: Hello, world!
	return 0;
}
