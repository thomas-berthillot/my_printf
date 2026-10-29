#include <stdlib.h>
#include "my.h"

char *my_utoa(unsigned int n)
{
    int len;
    char *str;

    len = num_len(n);
    str = alloc_str(len);
    if (str == NULL)
        return NULL;
    fill_num(str, n, len);
    return str;
}
