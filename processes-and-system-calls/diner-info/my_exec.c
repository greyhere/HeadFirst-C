#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>


int main()
{
    char *my_env[] = {"JUICE=peach and apple", NULL};

    execle("diner_info", "diner_info", "4", NULL, my_env);

    // if execle() worked, this line of code would never run
    puts(strerror(errno));
    return 0;
}
