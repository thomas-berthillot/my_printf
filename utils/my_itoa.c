#include <stdlib.h>
#include "my.h"

char *my_itoa(int n)
{
    long nb;
    int neg;
    int len;
    char *str;

    neg = (n < 0);
    nb = get_abs_int(n);
    len = num_len(nb) + neg;
    str = alloc_str(len);
    if (str == NULL)
        return NULL;
    fill_num(str, nb, len);
    if (neg)
        str[0] = '-';
    return str;
}
