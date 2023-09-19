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
ptr = va_arg(args, void *);

count += print_pointer(ptr);

return (count);
}


/**
 * print_pointer - a function that prints a hex number
 * @ptr: number to print
 * Return: count
*/

int print_pointer(const void *ptr)
{
char hex_digits[] = "0123456789ABCDEF";
unsigned long address = (unsigned long)ptr;
char hex_address[16];
int count = 0;
int index = 0;
write(1, "0x", 2);

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

while (index > 0)
write(1, &hex_address[--index], 1);

return (count);
}