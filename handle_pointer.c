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
char hex_digits[] = "0123456789abcdef";
unsigned long address;
void *ptr;
char hex_address[16];
int index;
index = 0;
ptr = va_arg(args, void *);
address = (unsigned long)ptr;
write(1, "0", 1);
write(1, "x", 1);
count += 2;

if (ptr == NULL)
	return (write(1, "(nil)", 5));

if (address == 0)
{
hex_address[index++] = '0';
count++;
}
else
{
while (address != 0)
{
	hex_address[index++] = hex_digits[address % 16];
	address /= 16;
	count++;
}
}

hex_address[index] = '\0';

while (index > 0)
write(1, &hex_address[--index], 1);

return (count);
}

