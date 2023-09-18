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
		{'%', print_per},
		{'d', print_int},
		{'i', print_int},
		{'b', print_bin}
	};

	while (i < 5)
	{
		if (ch == spc[i].ch)
			return (spc[i].f);
		i++;
	}

	return (NULL);
}
/**
 * print_per - prints percent
 * @args: list of arguments
 * @count: counter of printed characters
 * Return: the counter
 */
int print_per(va_list args, int count)
{
	char c = '%';

	(void) args;
	write(1, &c, 1);

	return (++count);
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
	if (s == NULL)
		s = "(null)";
	for (j = 0; s[j] != '\0'; j++)
	{
		write(1, &s[j], 1);
		count++;
	}

	return (count);
}

/**
 * print_bin - prints binary
 * @args: list of arguments
 * @count: counter of printed characters
 * Return: the counter
 */
int print_bin(va_list args, int count)
{
int arr[64];
int num, i = 0;
char bit;
num = va_arg(args, int);

if (num == 0)
{
	write(1, "0", 1);
	return (++count);
}

while (num != 0)
{
	arr[i] = num % 2;
	num /= 2;
	i++;
}

count += i;

for (i = i - 1; i >= 0; i--)
{
	bit = arr[i] + '0';
	write(1, &bit, 1);
}

return (count);
}
