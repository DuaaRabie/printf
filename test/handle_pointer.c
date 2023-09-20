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
	int i, h;
	char arr[16];
	long int numptr;

	ptr = va_arg(args, void*);

	numptr = &ptr;
	i = 0;
	while (numptr != 0)
	{
		h = (numptr % 16);
		if (h < 10)
			h += '0';
		else
			h += 'a' - 10;
		arr[i] = h;

		numptr /= 16;
		i++;
	}
	count += i;
	i--;
	while (i >= 0)
		write(1, &arr[i--], 1);

	return (count);
}
