#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int fc_puller(va_list *args, buffer_t *buf, flag_state_t *st)
{
    char c = (char)va_arg(*args, int);

    return emit_text(buf, st, &c, 1);
}
