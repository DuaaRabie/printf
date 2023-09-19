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
char *str;
int i;
i = 0;
str = va_arg(args, char *);

if (str == NULL)
	return (write(1, "(null)", 6));

while (str[i])
{
if ((str[i] < 32) || str[i] >= 127)
{
write(1, "\\", 1);
write(1, "x", 1);
write(1, "0", 1);
count += HEX_digit_print(str[i]) + 2;
}
else
{
write(1, &str[i], 1);
count++;
}
i++;
}

return (count);
}
