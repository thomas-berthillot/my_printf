#include <stdlib.h>
#include "my.h"

int num_len(unsigned long long nb)
{
    int len = 0;

    if (nb == 0)
        return 1;
    while (nb > 0) {
        nb /= 10;
        len++;
    }
    return len;
}

char *alloc_str(int len)
{
    char *str;

    str = malloc(sizeof(char) * (len + 1));
    if (str == NULL)
        return NULL;
    str[len] = '\0';
    return str;
}

void fill_num(char *str, unsigned long long nb, int len)
{
    if (nb == 0) {
        str[0] = '0';
        return;
    }
    while (nb > 0) {
        len--;
        str[len] = nb % 10 + '0';
        nb /= 10;
    }
}

long get_abs_int(int n)
{
    long nb;

    nb = n;
    if (nb < 0)
        nb = -nb;
    return nb;
}
