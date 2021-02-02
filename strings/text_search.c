#include <stdio.h>
#include <string.h>


char tracks[][80] = {
    "I left my heart in Havard Med School",
    "Newark, Newark - a wonderful town",
    "Dancing with a Dork",
    "From here to maternity",
    "The girl from Iwo Jima",
};


void find_track(char query[])
{
    int i;
    for (i = 0; i < 5; i++) {
        if (strstr(tracks[i], query))
            printf("Track %i: '%s'\n", i, tracks[i]);
    }
}


int main()
{
    char search_for[80];
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    find_track(search_for);
    return 0;
}
