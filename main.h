#ifndef MAIN_H_
#define MAIN_H_

#define BUFFER_SIZE 1024

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);

/* handle int with width and space */
int print_space(long int num, int width);
int check_width(int num, const char *format, int i);

/* handle int with width and space */
int o_digit_print(long int num);

/**
 * struct specifier - struct for specifer type and function
 * @ch: The specifier character
 * @f: The function associated
 */
typedef struct specifier
{
	char ch;
	int (*f)(va_list args, char* buffer);
} specifier;

/* specifiers */
int (*get_spc_fun(char ch))(va_list, char*);
int print_ch(va_list, char*);
int print_str(va_list, char*);
int print_per(va_list, char*);
int print_int(va_list, char*);
int print_bin(va_list, char*);
int print_uint(va_list, char*);
int print_oct(va_list, char*);
int print_hex(va_list, char*);
int print_HEX(va_list, char*);

#endif
