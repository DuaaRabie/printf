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

	while (i < 6)
	{
		if (ch == spc[i].ch)
			return (spc[i].f);
		i++;
	}

	return (NULL);
}
