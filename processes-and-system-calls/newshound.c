#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>


int main(int argc, char *argv[])
{
    // you can choose your own RSS feeds
    char *feeds[] = {
        "https://www.cnn.com/rss/celebs.xml",
        "https://www.rollingstone.com/rock.xml",
        "https://www.eonline.com/gossip.xml"
    };
    int times = 3;
    char *phrase = argv[1];
    
    for (int i = 0; i < times; i++) {
        char var[255];
        sprintf(var, "RSS_FEED=%s", feeds[i]);
        char *vars[] = {var, NULL};

        // first, call fork() to clone the process
        pid_t pid = fork();

        // if fork() returned -1, there was a problem cloning the process
        if (pid == -1) {
            fprintf(stderr, "Can't fork process: %s\n", strerror(errno));
            return 1;
        }

        // if fork() returned 0, the code is running in the child process
        if (!pid) {
            // if you are here, you are the child process
            // so we should call exec() the script
            if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", phrase, NULL, vars) == -1) {
                fprintf(stderr, "Can't run the script: %s\n", strerror(errno));
                return 1;
            }
        }
    }
    return 0;
}
