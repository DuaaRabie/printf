#include "main.h"

/**
 * to_hex - a function that converts an int to it's hex form
 * @n: number to convert
 * Return: the number in hex
 *
*/
int to_hex(int n)
{
int hold;
int count;
count = 0;
while (n != 0)
{
hold = n % 16;

if (hold < 10)
{
hold += '0';
write(1, &hold, 1);
}
else
{
hold += 'A' - 10;
write(1, &hold, 1);
}
count++;
n /= 16;
}
write(1, "x0", 2);
return (count);
}

/**
 * print_hex - a function that prints a hex number
 * @ptr: number to print
 * Return: count
*/

int print_hex(const void *ptr)
{
char hex_digits[] = "0123456789ABCDEF";
unsigned long long address = (unsigned long long)ptr;
char hex_address[16];
int count = 0;
int index = 0;
putchar('0');
putchar('x');

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
putchar(hex_address[--index]);

return (count);
}
/**
 * main - ...
 * Return: 0
*/

int main(void)
{
print_hex(&main);
printf("\n%p\n", &main);

return (0);
}

