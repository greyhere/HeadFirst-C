#include <stdio.h>
#include <string.h>


void print_reverse(char *s)
{
    size_t len = strlen(s);
    char *t = s + len - 1;
    while (t >= s) {
        printf("%c", *t);
        t = t - 1;
    }
    puts("");
}


int main() {
    char text[] = "string";
    print_reverse(text);
    return 0;
}
