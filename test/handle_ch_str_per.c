#include "main.h"

/**
 * print_per - prints percent
 * @args: list of arguments
 * @count: counter of printed characters
 * Return: the counter
 */
int print_per(va_list args, int count)
{
	char c = '%';

	(void) args;
	write(1, &c, 1);

	return (++count);
}

/**
 * print_ch - prints characters
 * @args: list of arguments
 * @count: counter of printed characters
 * Return: the counter
 */
int print_ch(va_list args, int count)
{
	unsigned char c;

	c = va_arg(args, int);
	write(1, &c, 1);

	return (++count);
}

/**
 * print_str - prints strings
 * @args: list of arguments
 * @count: counter of printed characters
 * Return: the counter
 */
int print_str(va_list args, int count)
{
	const char *s;
	int j;

	s = va_arg(args, char*);
	if (s == NULL)
		s = "(null)";
	for (j = 0; s[j] != '\0'; j++)
	{
		write(1, &s[j], 1);
		count++;
	}

	return (count);
}
