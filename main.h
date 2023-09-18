#ifndef MAIN_H_
#define MAIN_H_

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);

/* handle hec */
int to_hex(int n);
int print_hex(const void *ptr);

/* handle int with width and space */
int print_space(long int num, int width);
int print_int(va_list, int);
int check_width(int num, const char *format, int i);

/**
 * struct specifier - struct for specifer type and function
 * @ch: The specifier character
 * @f: The function associated
 */
typedef struct specifier
{
	char ch;
	int (*f)(va_list args, int count);
} specifier;

int (*get_spc_fun(char ch))(va_list, int);
int print_ch(va_list, int);
int print_str(va_list, int);
int print_per(va_list, int);
int print_bin(va_list, int);

#endif
