#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...);

/* handle hec */
int to_hex(int n);
int print_hex(const void *ptr);

/* handle int with width and space */
int print_space(long int num, int width);
int print_int(int c);
int check_width(int num, const char *format, int i);

#endif
