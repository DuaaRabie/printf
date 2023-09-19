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
