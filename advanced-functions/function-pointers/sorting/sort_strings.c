#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare_names(const void *a, const void *b)
{
    // A string is a pointer to char, so the pointers
    // we are given are pointers to pointers
    char **sa = (char **)a;
    char **sb = (char **)b;

    // we need to use the * operator to find the actual strings
    return strcmp(*sa, *sb);
}


int main()
{
    char *names[] = {"Karen", "Mark", "Brett", "Molly"};

    // an array of names is just an array of char pointers,
    // so the size of each item is sizeof(char *)
    qsort(names, 4, sizeof(char *), compare_names);

    puts("These are the names in order:");
    for (int i = 0; i < 4; i++)
        printf("%s\n", names[i]);

    return 0;
}
