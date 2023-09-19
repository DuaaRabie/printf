#include "main.h"

int rev_str(char *s);
/**
 * handel_rev - ...
 * @args: ...
 * @count: ...
 * Return: ....
*/
int handel_rev(va_list args, int count)
{
char *str;

str = va_arg(args, char *);

if (str == NULL)
	return (write(1, "(null)", 6));

count += rev_str(str);

return (count);
}


/**
 * rev_str - prints a string, in reverse, followed by a new line.
 *@s: targeted string
  * Return: ...
 */
int rev_str(char *s)
{

int l, h;
l = 0;
while (*(s + l) != '\0')
{
l++;
}
h = l;
l--;
while (l >= 0)
{
write(1, (s + l), 1);
l--;
}
return (h);
}


