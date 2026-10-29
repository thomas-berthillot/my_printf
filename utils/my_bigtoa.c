#include <stdlib.h>
#include "my.h"

char *mybigftoa(double n, int precision)
{
    char *str = my_ftoa(n, precision);

    if (str == NULL)
        return NULL;
    return uppercase(str);
}

char *my_bigetoa(double n, int precision)
{
    char *str = my_etoa(n, precision);

    if (str == NULL)
        return NULL;
    return uppercase(str);
}
