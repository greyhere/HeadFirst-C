#include "encrypt.h"


/* Simple XOR encryption */
void encrypt(char *message)
{
    while (*message) {
        *message = *message ^ 31;
        message++;
    }
}
