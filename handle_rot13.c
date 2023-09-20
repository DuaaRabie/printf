#include "main.h"

/**
 * print_rot13 - encode to rot13
 * @args: list of arguments
 * @count: the counter
 * Return: count
 */
int print_rot13(va_list args, int count)
{
	int i, j;
	char s1[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char s2[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str = va_arg(args, char*);

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; s1[j] != '\0' && s2[j] != '\0'; j++)
		{
			if (str[i] == s1[j])
			{
				count += write(1, &s2[j], 1);
				break;
			}
		}
		if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')))
			count += write(1, &str[i], 1);
	}

	return (count);
}
