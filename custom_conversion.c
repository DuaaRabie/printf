#include "main.h"

/**
 * handel_cstm - S : prints the string Non printable characters
 * (0 < ASCII value < 32 or >= 127)
 * are printed this way: \x, followed by the ASCII code value
 *  in hexadecimal (upper case - always 2 characters)
 * @args: ...
 * @count: ...
 * Return: number of bits printed
*/

int handel_cstm(va_list args, int count)
{
char *str, hold;
int i;
i = 0;
str = va_arg(args, char *);
	if (str == NULL)
		return (write(1, "(null)", 6));
while (str[i])
{
if (is_printable(str[i]))
count += write(1, &str[i], 1);
else
{
if ((int)str[i] < 16)
{
write(1, "\\", 1);
write(1, "x", 1);
write(1, "0", 1);
count += 4;
hold = str[i] % 16 + ((str[i] > 9) ? 'A' - 10 : '0');
write(1, &hold, 1);
}
else
{
count += HEX_digit_print(str[i]);
}
}
i++;
}
return (count);
}

/**
 * is_printable - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}
