#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

static char *find_char(char *str, char c)
{
    for (; *str; str++) {
        if (*str == c)
            return str;
    }
    return NULL;
}

static void copy_suffix(char *dest, char *src)
{
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

static void strip_zeros(char *str)
{
    char *dot = find_char(str, '.');
    char *e = find_char(str, 'e');
    char *end = e;

    if (dot == NULL)
        return;
    if (e == NULL) {
        end = str;
        while (*end)
            end++;
    }
    end--;
    while (*end == '0')
        end--;
    if (end == dot)
        end--;
    if (e != NULL)
        copy_suffix(end + 1, e);
    else
        end[1] = '\0';
}

static int trouver_lexposant(double nb)
{
    int exp = 0;

    if (nb == 0.0)
        return (0);
    if (nb >= 1.0) {
        while (nb >= 10.0) {
            nb /= 10.0;
            exp++;
        }
    } else {
        while (nb < 1.0) {
            nb *= 10.0;
            exp--;
        }
    }
    return (exp);
}

static char *normal_float(double n, int precision)
{
    double nb = get_absf(n);
    int x = trouver_lexposant(nb);
    char *str;

    if (x >= -4 && x < precision)
        str = my_ftoa(n, precision - (x + 1));
    else
        str = my_etoa(n, precision - 1);
    if (str != NULL)
        strip_zeros(str);
    return str;
}

char *my_gtoa(double n, int precision)
{
    char *str = special_value(n);

    if (precision < 0)
        precision = 6;
    if (precision == 0)
        precision = 1;
    if (str != NULL)
        return str;
    return normal_float(n, precision);
}
