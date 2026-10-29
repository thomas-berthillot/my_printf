#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

static double split(double nb)
{
    unsigned long long intpart = (unsigned long long)nb;
    double decpart = nb - intpart;

    return decpart;
}

static unsigned long long power(float f, int *d_out)
{
    double scaled;
    unsigned long long n;
    int d = 0;
    double p = 1.0;

    if (f < 0)
        f = -f;
    while (d <= 17){
        scaled = (double)f * p;
        if (scaled >= 9e18)
            break;
        n = (unsigned long long)(scaled + 0.5);
        if ((float)((double)n / p) == f)
            break;
        p *= 10.0;
        d++;
    }
    if (d_out)
        *d_out = d;
    return n;
}

static int count_digits(float f)
{
    int d = 0;
    unsigned long long n = power(f, &d);
    int len;

    len = 1;
    while (n >= 10){
        n /= 10;
        len++;
    }
    if (len < d + 1)
        len = d + 1;
    return len;
}

static void fill_digits(char *str, double nb, int len)
{
    double decpart = split(nb);
    unsigned long long intpart = nb - decpart;
    int len_int = num_len(intpart);
    int i = len_int - 1;

    if (intpart == 0)
        str[0] = '0';
    for (; intpart > 0 && i >= 0; i--) {
        str[i] = intpart % 10 + '0';
        intpart /= 10;
    }
    if (len > len_int)
        str[len_int] = '.';
    else
        str[len_int] = '\0';
    for (int y = len_int + 1; y <= len; y++) {
        decpart = decpart * 10;
        str[y] = (int)decpart + '0';
        decpart -= (int)decpart;
    }
}

static char *normal_float(double n, int precision)
{
    double nb = abs_rounded(n, precision);
    int len_int = num_len((unsigned long long)nb);
    int len;
    char *str;

    if (precision == -1) {
        len = count_digits(nb);
    } else {
        len = len_int + precision;
    }
    str = alloc_str(len + 1);
    if (str == NULL)
        return NULL;
    fill_digits(str, nb, len);
    return str;
}

char *my_ftoa(double n, int precision)
{
    char *str = special_value(n);

    if (str != NULL)
        return str;
    return normal_float(n, precision);
}
