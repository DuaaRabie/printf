#include "main.h"

/**
 * print_per - prints percent
 * @args: list of arguments
 * @buffer: the buffer
 * Return: size
 */
int print_per(va_list args, char *buffer)
{
	buffer[0] = '%';

	(void) args;

	return (1);
}

/**
 * print_ch - prints characters
 * @args: list of arguments
 * @buffer: the buffer
 * Return: size
 */
int print_ch(va_list args, char *buffer)
{
	unsigned char c = va_arg(args, int);

	buffer[0] = c;

	return (1);
}

/**
 * print_str - prints strings
 * @args: list of arguments
 * @buffer: the buffer
 * Return: size
 */
int print_str(va_list args, char *buffer)
{
	const char *s;
	int j = 0, size = 0;

	s = va_arg(args, char*);
	if (s == NULL)
		s = "(null)";
	while (s[j++])
	{
	size++;
	buffer[j] = s[j];
	}

	return (size);
}
