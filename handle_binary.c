#include "main.h"

/**
 * print_bin - prints binary
 * @args: list of arguments
 * @count: counter of printed characters
 * Return: the counter
 */
int print_bin(va_list args, int count)
{
int arr[64];
unsigned int num;
int i = 0;
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
