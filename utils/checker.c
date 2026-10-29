#include <stdlib.h>
#include "my.h"

int checker(double nb)
{
    if (nb != nb) {
        return 1;
    }
    if (nb != 0.0f && nb == nb * 2.0f) {
        return 2;
    }
    return 0;
}

char *special_value(double n)
{
    char *str;

    if (checker(n) == 0)
        return NULL;
    str = alloc_str(3);
    if (str == NULL)
        return NULL;
    if (checker(n) == 1)
        my_strcpy(str, "nan");
    else
        my_strcpy(str, "inf");
    return str;
}
