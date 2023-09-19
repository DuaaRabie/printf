#include "main.h"
#include <limits.h>

/**
 * print_binary - ...
 * @n: number to print
 * Return: the count of printed numbers
*/

int print_binary(int n)
{
int count = 0;
char digits[32];
int i = 0, j;

while (n != 0)
{
digits[i] = (n % 2) + '0';
n /= 2;
i++;
}
for (j = i - 1; j >= 0; j--)
{
write(1, &(digits[j]), 1);
count++;
}
return (count);
}


/* your b and S switch cases */
/*
c = va_arg(args, int);
count += print_binary(c);
case 'S':
c = va_arg(args, int);c = va_arg(args, int);
count += to_hex(c);
break;*/


/*
int main(void)
{

	_printf("myc name: %s, %c, %6i\n", "Duaa", 'D', -15);
	printf("myc name: %s, %c, %6i\n", "Duaa", 'D', -15);
	
	_printf("myc name: %s, %c, %4d no\n", "Omar", 'O', -2035065302);
	printf("myc name: %s, %c, %4d no\n", "Omar", 'O', -2035065302);

	int len;
	_printf("myc name: %s, %c, %i yes \n", "Duaa", 'D', -2035065302);
	_printf("myc name: %s, %c, %d no \n", "Omar", 'O', 1560133635);
	len = _printf("%b\n", 7);
	_printf("%d\n", len);
	printf("%S", "hi\n")
	len = printf("%b\n", 7);
	printf("%d\n", len);
	len = _printf("%d\n", 214);
	_printf("%d\n", len);
 

 
  *
  * int len;
  * int len2;
  * unsigned int ui;
  * void *addr;
  * len = _printf("Let's try to printf a simple sentence.\n");
  * len2 = printf("Let's try to printf a simple sentence.\n");
  * addr = (void *)0x7ffe637541f0;
  * ui = (unsigned int)INT_MAX + 1024;
  * _printf("%d\n", len);
   *_printf("Length:[%d, %i]\n", len, len);
   * printf("Length:[%d, %i]\n", len2, len2);
   * _printf("Negative:[%d]\n", -762534);
   * printf("Negative:[%d]\n", -762534);
   * _printf("Unsigned:[%u]\n", ui);
   * printf("Unsigned:[%u]\n", ui);
   * _printf("Unsigned octal:[%o]\n", ui);
   * printf("Unsigned octal:[%o]\n", ui);
   * _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
   * printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
   * _printf("Character:[%c]\n", 'H');
   * printf("Character:[%c]\n", 'H');
   * _printf("String:[%s]\n", "I am a string !");
   * printf("String:[%s]\n", "I am a string !");
   * _printf("Address:[%p]\n", addr);
   * printf("Address:[%p]\n", addr);
   * len = _printf("Percent:[%%]\n");
   * len2 = printf("Percent:[%%]\n");
   * _printf("Len:[%d]\n", len);
   * printf("Len:[%d]\n", len2);
   * _printf("Unknown:[%r]\n");
   * printf("Unknown:[%r]\n");
   *
	return (0); 
}*/


