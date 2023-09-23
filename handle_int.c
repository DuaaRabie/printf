#include "main.h"

/**
* print_flag - print space for width
* @num: the number
* @flagdigits: the width
* @flag: the flag to print
* Return: nothing
*/
int print_flag(long int num, int flagdigits, char flag)
{
	int count = 0;
	int digits = 1;

	if (num < 0)
	{
		num *= -1;
		digits++;
	}
	while (num / 10)
	{
		num /= 10;
		digits++;
	}

	while (flagdigits - digits > 0)
	{
		write(1, &flag, 1);
		count++;
		flagdigits--;
	}

	return (count);
}

/**
* digit_print - print integers
* @num: integer to print
* @sign: sign of the number
* Return: count
*/
int digit_print(long int num, int sign)
{
	char digit;
	int count = 0;

	if (sign != 0)
	{
		if (sign == 1)
			count += write(1, "+", 1);
		else if (sign == 2)
			count += write(1, " ", 1);
		else if (sign == -1)
			count += write(1, "-", 1);
		sign = 0;
	}

	if (num / 10 != 0)
		count += digit_print(num / 10, sign);
	digit = num % 10 + '0';
	write(1, &digit, 1);

	return (++count);
}


int print_int(va_list args, char *flags);

/**
* print_int - print integers
* @args: list of arguments
* @flags: list of flags
* Return: count
*/
int print_int(va_list args, char *flags)
{
	int j = 0;
	int flagdigits = 0;
	int count = 0, sign = 0;
	int align = 0;

	long int num = va_arg(args, int);

	while (flags[j] != '\0')
	{
		if (flags[j] >= '0' && flags[j] <= '9')
		{
			flagdigits = flags[j] - '0';
		}
		j++;
	}
	j = 0;

	if (num < 0)
	{
		sign = -1;
		num *= -1;
		flagdigits--;
	}

	while (flags[j] != '\0')
	{
		if (flags[j] >= '0' && flags[j] <= '9')
		{
			j++;
			if (flags[j] == '\0' && flagdigits != 0 && align != 1)
				count += print_flag(num, flagdigits, ' ');
			j--;
		}
		switch (flags[j])
		{
			case '+':
				if (sign != -1)
				{
					flagdigits--;
					sign = 1;
				}
				break;
			case '-':
				align = 1;
				break;
			case '0':
				if (sign == -1)
				{
					count += write(1, "-", 1);
					sign = 0;
				}
				else if (sign == 1)
				{
					count += write(1, "+", 1);
					sign = 0;
				}
				count += print_flag(num, flagdigits, '0');
				flagdigits = 0;
				break;
			case ' ':
				if (sign != -1)
				{
					flagdigits--;
					sign = 2;
				}
				break;
				default:
					break;
		}
		j++;
	}

	count += digit_print(num, sign);

	if (align == 1)
	count += print_flag(num, flagdigits, ' ');

	return (count);
}

/**
* print_uint - prints unsigned decimal
* @args: argument list
* @flags: the flags
* Return: counter
*/
int print_uint(va_list args, char *flags)
{
	int count = 0;
	unsigned int num = va_arg(args, int);

	(void) flags;
	count += digit_print(num, 0);

	return (count);
}
