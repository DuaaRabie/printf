#include "main.h"

/**
 * print_oct - prints octal
 * @args: argument list
 * @buffer: the buffer
 * Return: size
 */
int print_oct(va_list args, char *buffer)
{
	int len = 0, i;
	int num = va_arg(args, int), numlength = num;

	if (num == 0)
	{
		buffer[0] = '0';
		len = 1;
	}
	else
	{
		while (numlength)
		{
			numlength /= 8;
			len++;
		}
		i = len;
		while (num)
		{
			buffer[i - 1] = num % 8 + '0';
			num /= 8;
			i--;
		}
	}

	return (len);
}
