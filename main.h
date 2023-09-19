#ifndef MAIN_H_
#define MAIN_H_

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);

/* handle hex */
int hex_digit_print(unsigned long int num);
int HEX_digit_print(unsigned long int num);

/* handle int with width and space */
int print_space(long int num, int width);
int check_width(int num, const char *format, int i);
int digit_print(long int num);

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
	int (*f)(va_list args, int count);
} specifier;

/* specifiers */
int (*get_spc_fun(char ch))(va_list, int);
int print_ch(va_list, int);
int print_str(va_list, int);
int print_per(va_list, int);
int print_int(va_list, int);
int print_bin(va_list, int);
int print_uint(va_list, int);
int print_oct(va_list, int);
int print_hex(va_list, int);
int print_HEX(va_list, int);
int handel_cstm(va_list, int);
int print_pointer(const void *ptr);




int is_printable(char);
int handle_pointer(va_list args, int count);
int is_single_hex(int n);
int to_hex(long n);


#endif
