#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

static void fill_trucdevant(char *str, double nb, int precision)
{
    nb = nb + 0.0000005;
    str[0] = (int)nb + '0';
    nb = nb - (int)nb;
    str[1] = '.';
    for (int i = 2; i < precision + 2; i++) {
        nb = nb * 10;
        str[i] = (int)nb + '0';
        nb = nb - (int)nb;
    }
}

static void fill_digits(char *str, double nb, format_info_t *info)
{
    if (info->neg) {
        str[0] = '-';
        str = str + 1;
    }
    fill_trucdevant(str, nb, info->precision);
    fill_exposant(str + 2 + info->precision, info->exp);
}

static double calcul_exposant(double nb, int *exp)
{
    while (nb >= 10) {
        nb = nb / 10;
        *exp = *exp + 1;
    }
    while (nb < 1) {
        nb = nb * 10;
        *exp = *exp - 1;
    }
    return nb;
}

static char *alloc_zeroed(int len)
{
    char *str = alloc_str(len);

    if (str == NULL)
        return NULL;
    for (int i = 0; i < len; i++)
        str[i] = '\0';
    return str;
}

static char *normal_float(double n, int precision)
{
    format_info_t info;
    char *str;
    int exp = 0;
    double nb;

    info.neg = (n < 0);
    info.precision = (precision < 0) ? 6 : precision;
    if (n == 0) {
        str = alloc_str(12);
        return (str == NULL) ? NULL : e_for_0(str);
    }
    str = alloc_zeroed(info.precision + 20);
    if (str == NULL)
        return NULL;
    nb = calcul_exposant(get_absf(n), &exp);
    info.exp = exp;
    fill_digits(str, nb, &info);
    return str;
}

char *my_etoa(double n, int precision)
{
    char *str = special_value(n);

    if (str != NULL)
        return str;
    return normal_float(n, precision);
}
