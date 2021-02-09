#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>


void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}


int main(int argc, char *argv[])
{
    char *phrase = argv[1];
    char *vars[] = {"RSS_FEED=http://www.cnn.com/rss/celebs.xml", NULL};
    FILE *f = fopen("stories.txt", "w");
    
    // if we can't write to stories.txt, then f will be zero
    if (!f)
        error("Can't open stories.txt");

    pid_t pid = fork();
    if (pid == -1)
        error("Can't fork process");

    if (!pid) {
        // point descriptor #1 to the stories.txt
        if (dup2(fileno(f), 1) == -1)
            error("Can't redirect Standard Output");

        if (execle("/usr/bib/python", "/usr/bin/python", "./rssgossip.py", phrase, NULL, vars) == -1)
            error("Can't run script");
    }

    // wait for the child process to complete
    int pid_status;
    if (waitpid(pid, &pid_status, 0) == -1)
        error("Error waiting for the child process");

    return 0;
}
