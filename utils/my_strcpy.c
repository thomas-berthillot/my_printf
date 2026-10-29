#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    char *start = dest;

    while (*src != '\0'){
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return start;
}
