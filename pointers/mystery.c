#include <stdio.h>


int main()
{
    int doses[] = {1, 3, 2, 1000};

    // We can use an array variable like 'doses' as a pointer. So,
    // doses[3] == *(doses + 3) == *(3 + doses) == 3[doses]
    printf("Issue doses %i", 3[doses]);

    return 0;
}
