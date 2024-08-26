#include "ft_printf_bonus.h"
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>

int	main(void)
{
	int	x;

	// Mandatory Part
	printf("----- Mandatory Part -----\n");
	// Simple conversions
	ft_printf("Character: %c\n", 'A');
	printf("Character: %c\n", 'A');
	ft_printf("String: %s\n", "Hello");
	printf("String: %s\n", "Hello");
	ft_printf("Integer: %d\n", 42);
	printf("Integer: %d\n", 42);
	ft_printf("Unsigned: %u\n", 42);
	printf("Unsigned: %u\n", 42);
	ft_printf("Hex: %x\n", 255);
	printf("Hex: %x\n", 255);
	ft_printf("Hex (uppercase): %X\n", 255);
	printf("Hex (uppercase): %X\n", 255);
	ft_printf("Percent: %%\n");
	printf("Percent: %%\n");
	// Special cases
	ft_printf("Empty String: %s\n", "");
	printf("Empty String: %s\n", "");
	ft_printf("Null Pointer: %s\n", NULL);
	printf("Null Pointer: %s\n", "(null)");
	ft_printf("Zero Integer: %d\n", 0);
	printf("Zero Integer: %d\n", 0);
	ft_printf("Null char: %c\n", '\0');
	printf("Null char: %c\n", '\0');
	ft_printf("Special char: %c\n", '@');
	printf("Special char: %c\n", '@');
	// Multiple arguments/conversions
	ft_printf("Multiple: %d %s %c\n", 100, "test", 'X');
	printf("Multiple: %d %s %c\n", 100, "test", 'X');
	// Various conversions in a sentence
	ft_printf("Value: %d and hex: %x and char: %c\n", 123, 123, 'Y');
	printf("Value: %d and hex: %x and char: %c\n", 123, 123, 'Y');
	// Bonus Part
	printf("----- Bonus Part -----\n");
	// Test flags: '-' (left-justify), right-justify, '0' (zero padding)
	ft_printf("Left-justify: %-10d End\n", 42);
	printf("Left-justify: %-10d End\n", 42);
	ft_printf("Right-justify: %10d End\n", 42);
	printf("Right-justify: %10d End\n", 42);
	ft_printf("Zero-padding: %010d End\n", 42);
	printf("Zero-padding: %010d End\n", 42);
	// Test precision with integer
	ft_printf("Precision 5: %5d\n", 42);
	printf("Precision 5: %5d\n", 42);
	ft_printf("Precision 5 (zero padding): %05d\n", 42);
	printf("Precision 5 (zero padding): %05d\n", 42);
	// Test INT_MIN
	ft_printf("INT_MIN: %d\n", INT_MIN);
	printf("INT_MIN: %d\n", INT_MIN);
	// Test multiple flags
    ft_printf("Mixed Flags: %+5d\n", 42);
	printf("Mixed Flags: %+5d\n", 42);
	ft_printf("Mixed Flags: %+5d\n", -42);
	printf("Mixed Flags: %+5d\n", -42);
	ft_printf("Alternate form with hex: %#x\n", 255);
	printf("Alternate form with hex: %#x\n", 255);
	printf("----- Flags with All Conversions -----\n");
	// Test '#', '+', and space flags
	ft_printf("Hex (alternate): %#x\n", 255);
	printf("Hex (alternate): %#x\n", 255);
	ft_printf("Hex (uppercase, alternate): %#X\n", 255);
	printf("Hex (uppercase, alternate): %#X\n", 255);
	ft_printf("Signed (plus): %+d\n", 42);
	printf("Signed (plus): %+d\n", 42);
	ft_printf("Signed (space): % d\n", 42);
	printf("Signed (space): % d\n", 42);
	ft_printf("Signed (minus, zero padding): %-5d\n", 42);
	printf("Signed (minus, zero padding): %-5d\n", 42);
	// Test with zero padding and flags together
	ft_printf("Mixed flags: %05d\n", 42);
	printf("Mixed flags: %05d\n", 42);
	// Additional Edge Cases
	printf("----- Additional Edge Cases -----\n");
	// Testing with very large widths and precisions
	ft_printf("Large width: %100d\n", 42);
	printf("Large width: %100d\n", 42);
	ft_printf("Large precision: %.100d\n", 42);
	printf("Large precision: %.100d\n", 42);
	// Testing multiple identical conversions
	ft_printf("Multiple identical: %d %d %d %d %d\n", 1, 2, 3, 4, 5);
	printf("Multiple identical: %d %d %d %d %d\n", 1, 2, 3, 4, 5);
	// Complex format strings
	ft_printf("Complex: %-10.5d %#08x %+10.5d\n", 42, 255, -42);
	printf("Complex: %-10.5d %#08x %+10.5d\n", 42, 255, -42);
	// Testing `%p` with valid and null pointers
	x = 42;
	ft_printf("Pointer: %p\n", (void *)&x);
	printf("Pointer: %p\n", (void *)&x);
	ft_printf("Null pointer: %p\n", (void *)NULL);
	printf("Null pointer: %p\n", (void *)NULL);
	// Testing `%s` with long and special strings
	ft_printf("Long string: %s\n",
		"A very long string that exceeds typical buffer sizes...");
	printf("Long string: %s\n",
		"A very long string that exceeds typical buffer sizes...");
	ft_printf("Special string: %s\n", "Hello\nWorld\tTest");
	printf("Special string: %s\n", "Hello\nWorld\tTest");
	// Testing `%x` with small and large numbers
	ft_printf("Hex (lower): %x\n", 10);
	printf("Hex (lower): %x\n", 10);
	ft_printf("Hex zero: %x\n", 0);
	printf("Hex zero: %x\n", 0);
	// Testing percent sign
	ft_printf("Percent: %% %% %%\n");
	printf("Percent: %% %% %%\n");
	return (0);
}
