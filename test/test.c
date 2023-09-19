#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int handle_pointer(va_list args, int count)
{
    void *ptr;
    long hold;
    int i;
    int count_before = count;
    char hex_digits[] = "0123456789abcdef";

    ptr = va_arg(args, void *);
    hold = (long)ptr;

    write(1, "0x", 2);
    count += 2;

    for (i = sizeof(void *) * 2 - 1; i >= 0; i--)
    {
        int index = (hold >> (i * 4)) & 0xF;
        write(1, &hex_digits[index], 1);
        count++;
    }
  
    return count - count_before;
}

int main()
{
    void *ptr = &main;
    int count = handle_pointer(ptr, 0);
    printf("\nCount: %d\n", count);
    return 0;
}