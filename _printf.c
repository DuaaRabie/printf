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

	return (0);
}

/**
 * is_letter - check letters
 * @ch: character
 * Return: 1 || 0
 */
int is_letter(char ch)
{
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		return (1);

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
	int i, count = 0, k = 0;
	int (*spfun)(va_list, char*);
	char *flags = malloc(10);

	if (check_format(format) == -1)
		return (-1);

	va_start(args, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		k = 0;
		flags[k] = '\0';
		if (format[i] == '%')
		{
			if (format[i] == '%' && format[i + 1] == '\0' && format[i - 1] != '%')
				return (-1);
			i++;
			while (!(is_letter(format[i])) && format[i] != '%')
				flags[k++] = format[i++];
			flags[k] = '\0';
			spfun = get_spc_fun(format[i]);
			if (spfun != NULL)
				count += spfun(args, flags);
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

