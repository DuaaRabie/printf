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
	unsigned int j, count = 0;
	char *s;
	long int num;
	int c, i = 0;

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch(format[i])
			{
				case '%':
					c = va_arg(args, int);
					write(1, &c, 1);
					break;
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
				default:
					num = va_arg(args, long int);
					count += check_width(num, format, i);
					i += 2;
					continue;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
