#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int handle_pointer(va_list args, int count)
{
    void *ptr;
    int i, h;
    char arr[16];
    long numptr;

    ptr = va_arg(args, void *);

    numptr = (long)ptr;
    i = 0;
    while (numptr != 0)
    {
        h = (numptr % 16);
        if (h < 10)
            h += '0';
        else
            h += 'a' - 10;
        arr[i] = h;

        numptr /= 16;
        i++;
    }
    count += i;
    i--;
    while (i >= 0)
        write(1, &arr[i--], 1);

    return count;
}

int main()
{
    int count = handle_pointer(&main, 0);
    printf("\nCount: %d\n", count);
    return 0;
}