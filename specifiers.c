#include "main.h"

/**
 * get_spc_fun - a function that selects the correct specifier
 * @ch: the character determine th specifier
 * Return: a function pointer of the correct specifier
 */
int (*get_spc_fun(char ch))(va_list, char*)
{
	int i = 0;

	specifier spc[] = {
		{'c', print_ch},
		{'s', print_str},
		{'%', print_per},
		{'d', print_int},
		{'i', print_int},
		{'b', print_bin},
		{'u', print_uint},
		{'o', print_oct},
		{'x', print_hex},
		{'X', print_HEX},
		{'S', handel_cstm},
		{'p', handle_pointer},
		{'r', handel_rev},
		{'R', print_rot13}
	};

	while (i < 14)
	{
		if (ch == spc[i].ch)
			return (spc[i].f);
		i++;
	}

	return (NULL);
}
