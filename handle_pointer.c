#include "main.h"

/**
 * handle_pointer - Handle the following conversion specifier: p.
 * @args: ...
 * @count: number of bits printed
 *
 * Return: the new count
*/

int handle_pointer(va_list args, int count)
{
	void *ptr;
	long int numptr;

	ptr = va_arg(args, void*);

	if (ptr == NULL)
		count += write(1, "(nil)", 5);
	else
	{
		numptr = (long int)ptr;
		count += write(1, "0x", 2);
		count += hex_digit_print(numptr);
	}

	return (count);
}
