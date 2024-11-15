#include "ft_printf.h"

int	main()
{
	// ft_printf("1ST TEST:\n");
	// int l1 = printf("- alo %s 3alaykom, %% lyom %d f shher %i li howa %covember \n", "salamo", 9, 9, 'N');
	// int l2 = ft_printf("- alo %s 3alaykom, %% lyom %d f shher %i li howa %covember \n", "salamo", 9, 9, 'N');
	// ft_printf("\n+ length --> Mine : %d | --> OG : %d | %s\n\n", l1, l2, (l1 == l2) ? "OK" : "KO");

	// ft_printf("2ND TEST:\n");
	// l1 = ft_printf("-wash %s, 7na f %p fl memory\n", "a dyalna", "a dyalna");
	// l2 = printf("-wash %s, 7na f %p fl memory\n", "a dyalna", "a dyalna");
	// ft_printf("\n+ length --> Mine : %d | --> OG : %d | %s\n\n", l1, l2, (l1 == l2) ? "OK" : "KO");

	// ft_printf("3RD TEST:\n");
	// l1 = ft_printf("-hexa d 99999999 howa: %x lowercase | %X uppercase\n", 99999999, 99999999);
	// l2 = printf("-hexa d 99999999 howa: %x lowercase | %X uppercase\n", 99999999, 99999999);
	// ft_printf("\n+ length --> Mine : %d | --> OG : %d | %s\n\n", l1, l2, (l1 == l2) ? "OK" : "KO");

	// ft_printf("4TH TEST:\n");
	// l1 = ft_printf("-number [-24] unsigned int howa: [%u]\n", 24);
	// l2 = printf("-number [-24] unsigned int howa: [%u]\n", 24);
	// ft_printf("\n+ length --> Mine : %d | --> OG : %d | %s\n\n", l1, l2, (l1 == l2) ? "OK" : "KO");

	// ft_printf("5TH TEST:\n");
	// char	*s = "skill issue\n";
	// l1 = ft_printf("-%s", s);
	// l2 = printf("-%s", s);
	// ft_printf("\n+ length --> Mine : %d | --> OG : %d | %s\n\n", l1, l2, (l1 == l2) ? "OK" : "KO");

	// ft_printf("6TH TEST:\n");
	// l1 = ft_printf("a\n");
	// l2 = printf("a\n");
	// ft_printf("\n+ length --> Mine : %d | --> OG : %d | %s\n\n", l1, l2, (l1 == l2) ? "OK" : "KO");

	// ft_printf("7TH TEST:\n");
	// l1 = ft_printf("This %p is even stranger\n", (void *)-1);
	// l2 = printf("This %p is even stranger\n", (void *)-1);
	// ft_printf("\n+ length --> Mine : %d | --> OG : %d | %s\n\n", l1, l2, (l1 == l2) ? "OK" : "KO");

	// ft_printf("8TH TEST:\n");
	// l1 = ft_printf("%p\n", (void *)0);
	// l2 = printf("%p\n", (void *)0);
	// ft_printf("\n+ length --> Mine : %d | --> OG : %d | %s\n\n", l1, l2, (l1 == l2) ? "OK" : "KO");

	// ft_printf("9TH TEST:\n");
	// l1 = ft_printf("%c - %s - %p %d - %i - %u - %x %X %%\n", 'a', "test", (void *)0xdeadc0de, 20, -20, -1, -1, 200000000);
	// l2 = printf("%c - %s - %p %d - %i - %u - %x %X %%\n", 'a', "test", (void *)0xdeadc0de, 20, -20, -1, -1, 200000000);
	// ft_printf("\n+ length --> Mine : %d | --> OG : %d | %s\n\n", l1, l2, (l1 == l2) ? "OK" : "KO");

	// ft_printf("10TH TEST:\n");
	// l1 = ft_printf("%c\n", '\0');
	// l2 = printf("%c\n", '\0');
	// ft_printf("\n+ length --> Mine : %d | --> OG : %d | %s\n\n", l1, l2, (l1 == l2) ? "OK" : "KO");

	// ft_printf("11TH TEST:\n");
	// l1 = ft_printf("%i%i%i%i%i%i%i\n", 10, 23, -2, 37, 200, -9999, 977779);
	// l2 = printf("%i%i%i%i%i%i%i\n", 10, 23, -2, 37, 200, -9999, 977779);
	// ft_printf("\n+ length --> Mine : %d | --> OG : %d | %s\n\n", l1, l2, (l1 == l2) ? "OK" : "KO");

	// ft_printf("12TH TEST:\n");
	// l1 = ft_printf("hgjh%");
	// ft_printf("\n%d\n", l1);
	// l2 = printf("hgjh%");
	// printf("\n%d\n", l2);
	// ft_printf("\n+ length --> Mine : %d | --> OG : %d | %s\n\n", l1, l2, (l1 == l2) ? "OK" : "KO");

	// ft_printf("13TH TEST:\n");
	// l1 = ft_printf("%");
	// ft_printf("\n%d\n", l1);
	// l2 = printf("%");
	// printf("\n%d\n", l2);
	// ft_printf("\n+ length --> Mine : %d | --> OG : %d | %s\n\n", l1, l2, (l1 == l2) ? "OK" : "KO");

	// ft_printf("14TH TEST:\n");
	// l1 = ft_printf("%s %p", "hello", "hello");
	// printf("\n");
	// l2 = printf("%s %p", "hello", "hello");
	// ft_printf("\n+ length --> Mine : %d | --> OG : %d | %s\n\n", l1, l2, (l1 == l2) ? "OK" : "KO");

	//ft_printf("15TH TEST:\n");
	// int l1 = ft_printf("%d %d %s %p", 0, -2147483648, "", NULL);
	// ft_printf("\n%d\n", l1);
	// int l2 = printf("%d %d %s %p", 0, -2147483648, "", NULL);
	// printf("\n%d\n", l2);
	// ft_printf("\n+ length --> Mine : %d | --> OG : %d | %s\n\n", l1, l2, (l1 == l2) ? "OK" : "KO");

	// ft_printf("16TH TEST:\n");
	// int l1 = ft_printf("salam%slabas", "khuya");
	// ft_printf("\n%d\n", l1);
	// int l2 = printf("salam%slabas", "khuya");
	// printf("\n%d\n", l2);
	// ft_printf("\n+ length --> Mine : %d | --> OG : %d | %s\n\n", l1, l2, (l1 == l2) ? "OK" : "KO");

	// ---------------------------------------------------------------------------------------------------

    // // Test 1: Character conversion (%c)
    // printf("Char Test (expected: Char: A): ");
    // int r1 = printf("Char: %c\n", 'A');
    // int ft_r1 = ft_printf("Char: %c\n", 'A');
    // printf("Return values: printf = %d, ft_printf = %d\n\n", r1, ft_r1);

    // // Test 2: String conversion (%s)
    // printf("String Test (expected: String: Hello): ");
    // int r2 = printf("String: %s\n", "Hello");
    // int ft_r2 = ft_printf("String: %s\n", "Hello");
    // printf("Return values: printf = %d, ft_printf = %d\n\n", r2, ft_r2);

    // printf("Empty String Test (expected: Empty String: ): ");
    // int r3 = printf("Empty String: %s\n", "");
    // int ft_r3 = ft_printf("Empty String: %s\n", "");
    // printf("Return values: printf = %d, ft_printf = %d\n\n", r3, ft_r3);

    // printf("NULL String Test (expected: NULL Pointer: (null)): ");
    // int r4 = printf("NULL Pointer: %s\n", (char *)NULL);
    // int ft_r4 = ft_printf("NULL Pointer: %s\n", (char *)NULL);
    // printf("Return values: printf = %d, ft_printf = %d\n\n", r4, ft_r4);

    // // Test 3: Pointer conversion (%p)
    // printf("Pointer Test (expected: Pointer: (nil)): ");
    // int r5 = printf("Pointer: %p\n", (void *)0x0);
    // int ft_r5 = ft_printf("Pointer: %p\n", (void *)0x0);
    // printf("Return values: printf = %d, ft_printf = %d\n\n", r5, ft_r5);

    // // Test 4: Integer conversions (%d, %i)
    // printf("Integer Test (expected: Integer: 42): ");
    // int r6 = printf("Integer: %d\n", 42);
    // int ft_r6 = ft_printf("Integer: %d\n", 42);
    // printf("Return values: printf = %d, ft_printf = %d\n\n", r6, ft_r6);

    // printf("Negative Integer Test (expected: Negative Integer: -42): ");
    // int r7 = printf("Negative Integer: %d\n", -42);
    // int ft_r7 = ft_printf("Negative Integer: %d\n", -42);
    // printf("Return values: printf = %d, ft_printf = %d\n\n", r7, ft_r7);

    // printf("Smallest Integer Test (expected: Smallest Integer: -2147483648): ");
    // int r8 = printf("Smallest Integer: %d\n", INT_MIN);
    // int ft_r8 = ft_printf("Smallest Integer: %d\n", INT_MIN);
    // printf("Return values: printf = %d, ft_printf = %d\n\n", r8, ft_r8);

    // // Test 5: Unsigned integers (%u)
    // printf("Unsigned Test (expected: Unsigned: 42): ");
    // int r9 = printf("Unsigned: %u\n", 42);
    // int ft_r9 = ft_printf("Unsigned: %u\n", 42);
    // printf("Return values: printf = %d, ft_printf = %d\n\n", r9, ft_r9);

    // printf("Max Unsigned Test (expected: Max Unsigned: 4294967295): ");
    // int r10 = printf("Max Unsigned: %u\n", UINT_MAX);
    // int ft_r10 = ft_printf("Max Unsigned: %u\n", UINT_MAX);
    // printf("Return values: printf = %d, ft_printf = %d\n\n", r10, ft_r10);

    // // Test 6: Hexadecimal (%x, %X)
    // printf("Lowercase Hex Test (expected: Lowercase Hex: ff): ");
    // int r11 = printf("Lowercase Hex: %x\n", 255);
    // int ft_r11 = ft_printf("Lowercase Hex: %x\n", 255);
    // printf("Return values: printf = %d, ft_printf = %d\n\n", r11, ft_r11);

    // printf("Uppercase Hex Test (expected: Uppercase Hex: FF): ");
    // int r12 = printf("Uppercase Hex: %X\n", 255);
    // int ft_r12 = ft_printf("Uppercase Hex: %X\n", 255);
    // printf("Return values: printf = %d, ft_printf = %d\n\n", r12, ft_r12);

    // // Test 7: Percentage (%%)
    // printf("Percentage Test (expected: Percentage: % and text): ");
    // int r13 = printf("Percentage: %% and text\n");
    // int ft_r13 = ft_printf("Percentage: %% and text\n");
    // printf("Return values: printf = %d, ft_printf = %d\n\n", r13, ft_r13);

    // // Test 8: Multiple Arguments
    // printf("Multiple Arguments Test (expected: Multiple: 42, Test, ff): ");
    // int r14 = printf("Multiple: %d, %s, %x\n", 42, "Test", 255);
    // int ft_r14 = ft_printf("Multiple: %d, %s, %x\n", 42, "Test", 255);
    // printf("Return values: printf = %d, ft_printf = %d\n\n", r14, ft_r14);

    // // Test 9: Combinations
    // printf("Combo Test (expected: Combo: Hello, 123, ff, A): ");
    // int r15 = printf("Combo: %s, %d, %x, %c\n", "Hello", 123, 255, 'A');
    // int ft_r15 = ft_printf("Combo: %s, %d, %x, %c\n", "Hello", 123, 255, 'A');
    // printf("Return values: printf = %d, ft_printf = %d\n\n", r15, ft_r15);

	// ----------------------------------------------------------------------------

	// int a = ft_printf("%%%");
	// ft_printf("%d", a);
}
