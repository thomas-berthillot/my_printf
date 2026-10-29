#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int fs_puller(va_list *args, buffer_t *buf, flag_state_t *st)
{
    char *str = va_arg(*args, char *);
    int len;

    if (str == NULL)
        str = "(null)";
    len = my_strlen(str);
    if (st->precision >= 0 && st->precision < len)
        len = st->precision;
    return emit_text(buf, st, str, len);
}
