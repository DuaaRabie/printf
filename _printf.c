#include "main.h"
#include <string.h>

/**
 * _printf : prints a format
 * @format: the format to be printed
 * ...: variadic arguments
 * Return: number of printed characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned j, count = 0;
	char *s;
	int c, i = 0;
	char buffer[20];
	(void) buffer;


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
					j = 0;
					while (s[j])
					{
						write(1, s + j, 1);
						count++;
						j++;
					}
					break;
				case 'i':
				case 'd':
					break;
				default:
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

int main(void)
{
	_printf("myc name: %s, %c\n", "Duaa", 'D');
	_printf("myc name: %s, %c\n", "Omar", 'O');
	return 0;
}
