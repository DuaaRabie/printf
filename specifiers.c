#include "main.h"
/**
 * get_spc_fun - a function that selects the correct specifier
 * @ch: the character determine th specifier
 * Return: a function pointer of the correct specifier
 */
int (*get_spc_fun(char ch))(va_list, int)
{
	int i = 0;

	specifier spc[] = {
		{'c', print_ch},
		{'s', print_str},
		{'d', print_int},
		{'i', print_int}
	};

	while (i < 4)
	{
		if (ch == spc[i].ch)
			return (spc[i].f);
		i++;
	}

	return (NULL);
}
/**
 * print_ch - prints characters
 * @args: list of arguments
 * @count: counter of printed characters
 * Return: the counter
 */
int print_ch(va_list args, int count)
{
	unsigned char c;

	c = va_arg(args, int);
	write(1, &c, 1);

	return (++count);
}

/**
 * print_str - prints strings
 * @args: list of arguments
 * @count: counter of printed characters
 * Return: the counter
 */
int print_str(va_list args, int count)
{
	const char *s;
	int j;

	s = va_arg(args, char*);
	if (*s == '\0')
		s = "(null)";
	for (j = 0; s != NULL && s[j] != '\0'; j++)
	{
		write(1, s + j, 1);
		count++;
	}

	return (count);
}
