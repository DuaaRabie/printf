#include "main.h"

/**
 * handle_pointer - Handle the following conversion specifier: p.
 * @args: ...
 * @flags: the flags
 *
 * Return: the new count
*/

int handle_pointer(va_list args, char *flags)
{
	int count = 0;
	void *ptr;
	long int numptr;

	(void) flags;
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
