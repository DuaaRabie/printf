#ifndef MAIN_H_
#define MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int _printf(const char *format, ...);

/* handle hex */
int hex_digit_print(unsigned long int num);
int HEX_digit_print(unsigned long int num);

/* handle int with width and space */
int print_flag(long int num, int digits, char flag);
int check_width(int num, const char *format, int i);
int digit_print(long int num, int sign);

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
	int (*f)(va_list args, char *flags);
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
int handel_cstm(va_list, char*);
int handel_rev(va_list, char*);
int handle_pointer(va_list, char*);
int print_rot13(va_list, char*);

int print_pointer(const void *ptr);
int is_printable(char);
int is_single_hex(int n);
int to_hex(long n);

#endif
