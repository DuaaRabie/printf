#include "main.h"
/**
 * check_format - check if there is special cases in the format
 * @format: the format to be printed
 * Return: 0 || -1
 */
int check_format(const char *format)
{
	if (format == NULL)
	{
		return (-1);
	}
	while (*format)
	{
		if (*format == '%' && *(format + 1) == '\0' && *(format - 1) != '%')
		{
			return (-1);
		}

		format++;
	}
	return (0);
}
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

	if (check_format(format) == -1)
		return (-1);

	va_start(args, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			spfun = get_spc_fun(format[i]);
			if (spfun != NULL)
				count = spfun(args, count);
			else
				count += write(1, &format[--i], 1);
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

