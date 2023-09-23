#include "main.h"

/**
 * HEX_digit_print - print integers
 * @num: integer to print
 * Return: count
 */
int HEX_digit_print(unsigned long int num)
{
	int count = 0;
	char digit;

	if (num / 16 != 0)
		count += HEX_digit_print(num / 16);
	digit = num % 16;
	if (digit >= 0 && digit <= 9)
		digit += '0';
	else
		digit = digit - 10 + 'A';
	write(1, &digit, 1);

	return (++count);
}

/**
 * print_HEX - prints unsigned decimal
 * @args: argument list
 * @flags: the flags
 * Return: counter
 */
int print_HEX(va_list args, char *flags)
{
	int count = 0;
	unsigned int num;

	(void) flags;
	num = va_arg(args, int);
	count += HEX_digit_print(num);

	return (count);
}
