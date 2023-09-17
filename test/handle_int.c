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
 * digit_print - print integers
 * @c: integer to print
 * Return: count
 */
int digit_print(long int num)
{
	int count = 0;
	char digit;

	if (num / 10 != 0)
		count += digit_print(num / 10);
	digit = num % 10 + '0';
	write(1, &digit, 1);

	return (++count);
}

/**
 * print_int - print integers
 * @args: list of arguments
 * @count: the counter
 * Return: count
 */
int print_int(va_list args, int count)
{
	long int num = va_arg(args, int);

	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
		count++;

	}
	
	count += digit_print(num);

	return (count++);
}
/**
 * check_width - check width and print needed spaces
 * @num: the integer
 * @format: the format of printing
 * @i: the index
 * Return: nothing
 */
/*
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
}*/
