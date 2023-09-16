#include "main.h"

/**
 * print_space - print space for width
 * @num: the number
 * @width: the width
 * Return: nothing
 */
int print_space(long int num, int width)
{
	int count = 0;
	int digits = 1;

	if (num < 0)
	{
		num *= -1;
		digits++;
	}
	while (num / 10)
	{
		num /= 10;
		digits++;
	}

	while (width - digits > 0)
	{
		write(1, " ", 1);
		count++;
		width--;
	}

	return (count);
}

/**
 * print_int - print integers
 * @c: integer to print
 * Return: count
 */
int print_int(int c)
{
	char digit;
	int count = 0;

	if (c < 0)
	{
		write(1, "-", 1);
		c *= -1;
		count++;

	}
	if (c / 10 != 0)
	count += print_int(c / 10);
	digit = c % 10 + '0';
	write(1, &digit, 1);

	return (count++);
}
/**
 * check_width - check width and print needed spaces
 * @num: the integer
 * @format: the format of printing
 * @i: the index
 * Return: nothing
 */
int check_width(int num, const char *format, int i)
{
	int count = 0;

	if (format[i + 1] == 'd' || format[i + 1] == 'i')
	{
		if (format[i] > '0' && format[i] <= '9')
		{
			count += print_space(num, format[i] - 48);
			count += print_int(num);
		}
	}
	return (count);
}
