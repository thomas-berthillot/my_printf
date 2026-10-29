#include "my.h"

void str_upper(char *str)
{
    for (; *str != '\0'; str++) {
        if (*str >= 'a' && *str <= 'z')
            *str = *str - 'a' + 'A';
    }
}
