#include "main.h"

/**
 * print_hex - prints hexdecimal in small
 * @args: argument list
 * @buffer: the buffer
 * Return: size
 */
int print_hex(va_list args, char *buffer)
{
	int len = 0, remainder, i;
	unsigned int num = va_arg(args, int), numlength = num;

	if (num == 0)
	{
		buffer[0] = '0';
		len = 1;
	}

	else
	{
		while (numlength)
		{
			numlength /= 16;
			len++;
		}
		i = len;
		while (num)
		{
			remainder = num % 16;
			buffer[i - 1] = (remainder < 10) ? remainder + '0' : remainder + 'a' - 10;
			num /= 16;
			i--;
		}

	}

	return (len);
}
