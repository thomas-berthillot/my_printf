#include <stdarg.h>
#include <stdlib.h>
#include "my.h"


int fu_puller(va_list *args, buffer_t *buf, flag_state_t *st)
{
    unsigned int nb = va_arg(*args, unsigned int);
    char *str = my_utoa(nb);
    int ret;

    if (str == NULL)
        return -1;
    ret = emit_number(buf, st, "", str);
    free(str);
    return ret;
}
