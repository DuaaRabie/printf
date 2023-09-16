#include "main.h"

/**
 * _printf - prints a format
 * @format: the format to be printed
 * ...: variadic arguments
 * Return: number of printed characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	int j, count = 0, c, i;
	char *s;
	long int num;

	va_start(args, format);
	for (i = 0; format != NULL && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			switch (format[++i])
			{
				case 'c':
					c = va_arg(args, int);
					write(1, &c, 1);
					count++;
					break;
				case 's':
					s = va_arg(args, char*);
					for (j = 0; s[j] != '\0'; j++)
					{
						write(1, s + j, 1);
						count++;
					}
					break;
				case 'i':
				case 'd':
					num = va_arg(args, long int);
					count += print_int(num);
					break;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
