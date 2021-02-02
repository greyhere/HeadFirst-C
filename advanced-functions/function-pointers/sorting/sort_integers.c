#include <stdio.h>
#include <stdlib.h>


int compare_scores(const void *score_a, const void *score_b)
{
    // we need to cast the void pointer to an integer pointer
    // the first * then gets the int stored at address score_a
    int a = *(int *)score_a;
    int b = *(int *)score_b;

    // Avoid return x - y, which can cause undefined behaviour
    // because of signed integer overflow.
    return (a > b) - (a < b);
}


int main()
{
    int scores[] = {543, 323, 32, 554, 11, 3, 112};
    int i;

    qsort(scores, 7, sizeof(int), compare_scores);
    puts("These are the scores in order:");
    for (i = 0; i < 7; i++)
        printf("Score = %i\n", scores[i]);
    
    return 0;
}
