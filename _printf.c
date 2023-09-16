#include "main.h"

/**
 * print_space : print space for width
 * @num: the number
 * @w: the width
 * Return: nothing
 */
void print_space(long int num, int w)
{
	int count = 1;

	if (num < 0)
		num *= -1;
	while (num / 10)
	{
		count++;
		num /= 10;
	}
	while (w - count > 0)
	{
		write(1, " ", 1);
		w--;
	}
}

/**
 * pritn_int - print integers
 * @c: integer to print
 * Return: nothing
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
 * check_width - check width and print needed spaces
 * @num: the integer
 * @format: the format of printing
 * @i: the index
 * Return: nothing
 */
int check_width(int num, const char *format, int i)
{
	if (format[i + 2] == 'd' || format[i + 2] == 'i')
	{
		if (format[i + 1] > '0' && format[i + 1] <= '9')
		{
			print_space(num, format[i + 1] - 48);
			print_int(num);
			i +=2;
		}
	}
	return (i);
}
/**
 * _printf - prints a format
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
		/*	if (format[i + 2] == 'd' || format[i + 2] == 'i')
			{
				if (format[i + 1] > '0' && format[i + 1] <= '9')
				{
					num = va_arg(args, long int);
					print_space(num, format[i + 1] - 48);
					print_int(num);
					i += 2;
				}
			}*/
	
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
						for (j = 0; s[j] != '\0'; j++)
						{
							write(1, s + j, 1);
							count++;
						}
						break;
					case 'i':
					case 'd':
						num = va_arg(args, long int);
						i = check_width(num, format, i);
						print_int(num);
						break;
					default:
						continue;
				}
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
	_printf("myc name: %s, %c, %8d yes\n", "Duaa", 'D', 12);
	_printf("myc name: %s, %c, %i no\n", "Omar", 'O', -2035065302);
	return 0;
}
