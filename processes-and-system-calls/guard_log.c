/**
 * This program creates operating system command string that displays
 * the text comment, followed by the timestamp.
 *
 * WARNING: The user can use this program to run any command he/she
 *          likes on the computer by injecting some command line code
 *          into the text. eg: ' && ls / && echo '
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// this function returns a string containing the current date and time
char *now()
{
    time_t t;
    time (&t);
    return asctime(localtime (&t));
}


/**
 * Master Control Program utility.
 * Records guard patrol check-ins.
 */
int main()
{
    char comment[80];
    char cmd[120];

    fgets(comment, 80, stdin);
    
    // sprintf will print the characters to a string
    sprintf(cmd, "echo '%s %s' >> reports.log", comment, now());
    system(cmd);
    return 0;
}
