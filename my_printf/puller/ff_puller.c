#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int ff_puller(va_list *args, buffer_t *buf, flag_state_t *st)
{
    char *str;
    int ret;
    int precision = 6;
    double val = va_arg(*args, double);
    char const *prefix = float_prefix(val, st);
    flag_state_t copie = *st;

    if (st->precision != -1)
        precision = st->precision;
    str = my_ftoa(val, precision);
    copie.precision = -1;
    if (str == NULL)
        return -1;
    if (str[0] > '9')
        copie.zero = false;
    ret = emit_number(buf, &copie, prefix, str);
    free(str);
    return ret;
}
