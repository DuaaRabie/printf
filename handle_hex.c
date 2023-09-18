#include "main.h"
/**
 * hex_digit_print - print integers
 * @num: integer to print
 * Return: count
 */
int hex_digit_print(unsigned long int num)
{
	int count = 0;
	char digit;

	if (num / 16 != 0)
		count += hex_digit_print(num / 16);
	digit = num % 16;
	if (digit >= 0 && digit <= 9)
		digit += '0';
	else
		digit = digit - 10 + 'a';
	write(1, &digit, 1);

	return (++count);
}


/**
 * print_hex - prints unsigned decimal
 * @args: argument list
 * @count: the counter
 * Return: counter
 */
int print_hex(va_list args, int count)
{
	unsigned long int num;

	num = va_arg(args, int);
	count += hex_digit_print(num);

	return (count);
}
