#include "main.h"

/**
 * o_digit_print - print integers
 * @num: integer to print
 * Return: count
 */
int o_digit_print(long int num)
{
	int count = 0;
	char digit;

	if (num / 8 != 0)
		count += o_digit_print(num / 8);
	digit = num % 8 + '0';
	write(1, &digit, 1);

	return (++count);
}


/**
 * print_oct - prints unsigned decimal
 * @args: argument list
 * @flags: the flags
 * Return: counter
 */
int print_oct(va_list args, char *flags)
{
	unsigned int num;
	int count = 0;

	(void) flags;

	num = va_arg(args, int);
	count += o_digit_print(num);

	return (count);
}
