#include <stdio.h>
#include <stdarg.h>


void print_ints(int args, ...)
{
    va_list ap;
    va_start(ap, args);

    for (int i = 0; i < args; i++)
        printf("argument: %i\n", va_arg(ap, int));

    va_end(ap);
}


int main()
{
    print_ints(3, 79, 101, 32);
}
