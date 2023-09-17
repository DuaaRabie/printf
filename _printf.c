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
	int count = 0, i;
	int (*spfun)(va_list, int);

	if (format == NULL)
	{
		return (-1);
	}

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			if (format[i] == '%')
			{
				write(1, &format[i], 1);
				count++;
			}
			else
			{
				spfun = get_spc_fun(format[i]);
				if (spfun != NULL)
					count = spfun(args, count);
			}
		}
		else if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
