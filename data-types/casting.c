#include <stdio.h>


int main()
{
    int x = 7;
    int y = 2;

    // the compiler will automatically cast y to a float.
    float z = (float)x / y;
    printf("z = %f\n", z);

    return 0;
}
