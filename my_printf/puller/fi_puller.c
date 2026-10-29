#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

static char *prefix_switch(flag_state_t *st)
{
    if (st->plus)
        return "+";
    if (st->space)
        return " ";
    return "";
}

int fi_puller(va_list *args, buffer_t *buf, flag_state_t *st)
{
    char *str = my_itoa(va_arg(*args, int));
    char *modified_str = str;
    int ret;
    char *prefix = "";

    if (str == NULL)
        return -1;
    prefix = prefix_switch(st);
    if (str[0] == '-'){
        prefix = "-";
        modified_str++;
    }
    ret = emit_number(buf, st, prefix, modified_str);
    free(str);
    return ret;
}
