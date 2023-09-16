#include "main.h"

/**
 * conv_spec - determine the conversion specifier
 * @format: format to be printed
 * @i: index of character
 * @args: list of arguments
 * Return: counter of printing
 */
/*
int conv_spec(const char *format, va_list args, int i, int count)
{
	int c, j;
	char *s;

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
		case '%':
			write(1, &format[i], 1);
			count++;
			break;
	}
	return (count);
}
*/
/**
 * _printf - prints a format
 * @format: the format to be printed
 * ...: variadic arguments
 * Return: number of printed characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, i;
	int (*spfun)(va_list, int);

	va_start(args, format);
	for (i = 0; format != NULL && format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			i++;
			spfun = get_spc_fun(format[i]);
			count = spfun(args, count);
		}
		else
		{
			if (format[i] == '%' && format[i + 1] == '%')
				i++;
			write(1, &format[i], 1);
			count++;

		}
	}
	va_end(args);
	return (count);
}
