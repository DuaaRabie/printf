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
	va_list arg;
	unsigned j, count = 0;
	char *s;
	int c, i = 0;
	char buffer[20];
	(void) buffer;


	va_start(arg, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch(format[i])
			{
				case '%':
					c = va_arg(arg, int);
					write(1, &c, 1);
					break;
				case 'c':
					c = va_arg(arg, int);
					write(1, &c, 1);
					count++;
					break;
				case 's':
					s = va_arg(arg, char*);
					for (j = 0; j < strlen(s); j++)
					{
						write(1, s + j, 1);
						count++;
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
	va_end(arg);

	return (count);
}

int main(void)
{
	_printf("myc name: %s, %c\n", "Duaa", 'D');
	return 0;
}
