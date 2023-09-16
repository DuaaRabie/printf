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
int i = 0;
while (n != 0)
{
digits[i] = (n % 2) + '0';
n /= 2;
i++;
}
for (int j = i - 1; j >= 0; j--)
{
write(1, &(digits[j]), 1);
count++;
}
return (count);
}

/**
 * print_int - print integer
 * @c: integer to print
 */ 
int print_int(int c)
{
	char digit;
	int count;
	count = 0;

	if (c < 0)
	{
		write(1, "-", 1);
		c *= -1;
	}
	if (c / 10 != 0)
	count += print_int(c / 10);
	digit = c % 10 + '0';
	write(1, &digit, 1);


	return (count + 1);
}

/**
 * _printf : prints a format
 * @format: the format to be printed
 * ...: variadic arguments
 * Return: number of printed characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned j, count = 0;
	char *s;
	long int num;
	int c, i = 0;


	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch(format[i])
			{
				case '%':
					c = va_arg(args, int);
					write(1, &c, 1);
					break;
				case 'c':
					c = va_arg(args, int);
					write(1, &c, 1);
					count++;
					break;
				case 's':
					s = va_arg(args, char*);
					j = 0;
					while (s[j])
					{
						write(1, s + j, 1);
						count++;
						j++;
					}
					break;
				case 'b':
				c = va_arg(args, int);
				count += print_binary(c);
				case 'S':
				c = va_arg(args, int);
				count += to_hex(c);
				break;
				case 'i':
				case 'd':
					num = va_arg(args, long int);
					count += print_int(num);
					break;
				default:
					continue;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);

	return (count);
}

int main(void)
{
	int len;
	_printf("myc name: %s, %c, %i yes \n", "Duaa", 'D', -2035065302);
	_printf("myc name: %s, %c, %d no \n", "Omar", 'O', 1560133635);
	len = _printf("%b\n", 7);
	_printf("%d\n", len);
	printf("%S", "hi\n")
/* 	len = printf("%b\n", 7);
	printf("%d\n", len); */
/* 	len = _printf("%d\n", 214);
	_printf("%d\n", len); */


	

 /**
  *
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
   **/
	return (0);
}
