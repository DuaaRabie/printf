#include "main.h"

/**
 * print_int - prints decimal
 * @args: argument list
 * @buffer: the buffer
 * Return: size
 */
int print_int(va_list args, char *buffer)
{
	int len = 0, i;
	int num = va_arg(args, int), numlength = num;

	if (num == 0)
	{
		buffer[0] = '0';
		len = 1;
	}

	if (num < 0)
	{
		num *= -1;
		len = 1;
		buffer[0] = '-';
	}
	else
	{
		while (numlength)
		{
			numlength /= 10;
			len++;
		}
		i = len;
		while (num)
		{
			buffer[i - 1] = num % 10 + '0';
			num /= 10;
			i--;
		}
	}

	return (len);
}

/**
 * print_uint - prints unsigned decimal
 * @args: argument list
 * @buffer: the buffer
 * Return: size
 */
int print_uint(va_list args, char  *buffer)
{
	int len = 0, i;
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
			numlength /= 10;
			len++;
		}
		i = len;
		while (num)
		{
			buffer[i - 1] = num % 10 + '0';
			num /= 10;
			i--;
		}

	}

	return (len);
}
