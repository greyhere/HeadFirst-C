#include "encrypt.h"


/* Simple XOR encryption */
void encrypt(char *message)
{
    char c;
    while (*message) {
        *message = *message ^ 31;
        message++;
    }
}
