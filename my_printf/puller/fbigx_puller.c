#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

char *uppercase(char *hex)
{
    for (int i = 0; hex[i] != '\0'; i++){
        if (hex[i] >= 'a' && 'z' >= hex[i]){
            hex[i] = hex[i] - ('a' - 'A');
        }
    }
    return hex;
}

int fbigx_puller(va_list *args, buffer_t *buf, flag_state_t *st)
{
    unsigned int nb = va_arg(*args, unsigned int);
    int len = hex_len(nb);
    char *hex = unpeutout_hex(nb, len);
    int ret;
    char const *prefix = "";

    if (hex == NULL)
        return -1;
    uppercase(hex);
    if (st->hash && nb != 0)
        prefix = "0X";
    ret = emit_number(buf, st, prefix, hex);
    free(hex);
    return ret;
}
