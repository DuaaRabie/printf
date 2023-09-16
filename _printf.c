#include "main.h"

/**
 * print_int - print integer
 * @c: integer to print
 * Return: 0
 */
void print_int(int c)
{
	char digit;

	if (c < 0)
	{
		write(1, "-", 1);
		c *= -1;
	}
	if (c / 10 != 0)
		print_int(c / 10);
	digit = c % 10 + 48;
	write(1, &digit, 1);
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
				case 'i':
				case 'd':
					num = va_arg(args, long int);
					print_int(num);
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
	_printf("myc name: %s, %c, %i yes \n", "Duaa", 'D', -2035065302);
	_printf("myc name: %s, %c, %d no \n", "Omar", 'O', 1560133635);
	return 0;
}
