#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int to_hex(int n);
int print_hex(const void *ptr);
#endif
