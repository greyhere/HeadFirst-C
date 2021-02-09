#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


// This is our new signal handler.
void diediedie(int sig)
{
    puts("Goodbye cruel world...\n");
    exit(1);
}


// helper function to register a handler
int catch_signal(int sig, void (*handler)(int))
{
    // create an action
    struct sigaction action;
    
    // set the action's handler to the handler function that was passed in
    action.sa_handler = handler;

    // the mask is a way of filtering the signals that the sigaction will handle
    // we'll usually want to use an empty mask, like here
    sigemptyset(&action.sa_mask);
    
    // these are some additional flags, we can just set them to zero
    action.sa_flags = 0;

    // return the value of sigaction() so we can check for errors
    return sigaction(sig, &action, NULL);
}


int main()
{
    // capture the interrupt signal and set the interrupt handler to our
    // new signal handler function
    if (catch_signal(SIGINT, diediedie) == -1) {
        fprintf(stderr, "Can't map the handler");
        exit(2);
    }

    char name[30];
    printf("Enter your name: ");
    fgets(name, 30, stdin);
    printf("Hello %s\n", name);
    return 0;
}
