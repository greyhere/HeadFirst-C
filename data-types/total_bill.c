#include <stdio.h>


float total = 0.0;
short count = 0;
short tax_percent = 6;


// we're returning small cash value, so it'll be a float
float add_with_tax(float f)
{
    // a float will be OK for this fraction
    float tax_rate = 1 + tax_percent / 100.0;
                                     // by adding .0, we make the calculation
                                     // work as a float. If we left it as 100,
                                     // it would have returned a whole number.
                                     // 1 + tax_percent / 100, would return the
                                     // value 1 because tax_percent / 100 == 0
                                     // in integer arthmetic.
    total = total + (f * tax_rate);
    count = count + 1;
    return total;
}


int main()
{
    float val;
    printf("Price of item: ");
    while (scanf("%f", &val) == 1) {
        printf("Total so far: %.2f\n", add_with_tax(val));
        printf("Price of item: ");
    }

    printf("\nFinal total: %.2f\n", total);
    printf("Number of items: %hi\n", count);
    return 0;
}
