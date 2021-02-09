#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>


void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}


/**
 * This function runs three separate commands to open a URL.
 * Two of the commands will always fail, but as long as
 * the third command works, that'll be fine.
 */
void open_url(char *url)
{
    char launch[255];

    // this will open a web page on Windows
    sprintf(launch, "cmd /c start %s", url);
    system(launch);

    // this will open a web page on Linux
    sprintf(launch, "x-www-browser '%s' &", url);
    system(launch);

    // this will open a web page on the Mac
    sprintf(launch, "open '%s'", url);
    system(launch);
}


int main(int argc, char *argv[])
{
    char *phrase = argv[1];
    char *vars[] = {"RSS_FEED=https://www.cnn.com/rss/celebs.xml", NULL};

    // the descriptors created by pipe() will be stored in this array
    int fd[2];

    // pipe(fd) will creates two descriptors, that's:
    // fd[0] - read-end of pipe
    // fd[1] - write-end of pipe
    if (pipe(fd) == -1)
        error("Can't create the pipe");

    pid_t pid = fork();
    if (pid == -1)
        error("Can't fork process");

    // you're in the child process here
    if (!pid) {
        // redirect the Standard Output to the write end of the pipe
        dup2(fd[1], 1);

        // the child won't read from the pipe, so we'll close the read end
        close(fd[0]);

        if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py",
                    "-u", phrase, NULL, vars) == -1)
            error("Can't run script");
    }

    // you're in the parent process down here
    // so, redirect the Standard Input to the read end of the pipe
    dup2(fd[0], 0);

    // close the write end of the pipe, because the parent won't write to it
    close(fd[1]);

    // now read form Standard Input, because that's connected to the pipe
    // we could also have read from fd[0]
    char line[255];
    while (fgets(line, 255, stdin))
        if (line[0] == '\t')
            open_url(line + 1);

    return 0;
}
