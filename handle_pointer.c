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
long hold;
void *address;

write(1, "\\", 1);
write(1, "x", 1);
count += 2;

address = va_arg(args, void *);


hold = (unsigned long)address;


return (count);
}

