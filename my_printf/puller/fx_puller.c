#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

char calcul_hexa(unsigned nb)
{
    int remainder = 0;
    char chex;

    remainder = nb % 16;
    nb = nb / 16;
    if (remainder > 9) {
        chex = 'a' + (remainder - 10);
    } else {
        chex = '0' + remainder;
    }
    return chex;
}

static char *zero_case(char *str)
{
    str[0] = '0';
    str[1] = '\0';
    return str;
}

static int fill_hexa_digits(unsigned int nb, char *hexaNum)
{
    int i = 0;

    for (i = 0; nb != 0; i++){
        hexaNum[i] = calcul_hexa(nb);
        nb = nb / 16;
    }
    return i;
}

static void fill_str_hex(char *str, char *hexaNum, int len)
{
    int a = 0;

    for (int y = len - 1; y >= 0; y--){
        str[a] = hexaNum[y];
        a++;
    }
    str[len] = '\0';
}

char *unpeutout_hex(unsigned int nb, int len)
{
    char hexaNum[12];
    char *str = malloc(sizeof(char) * (len + 1));

    if (str == NULL)
        return NULL;
    if (nb == 0)
        return zero_case(str);
    fill_hexa_digits(nb, hexaNum);
    fill_str_hex(str, hexaNum, len);
    return str;
}

int hex_len(unsigned int nb)
{
    int len = 0;

    if (nb == 0)
        return 1;
    while (nb != 0) {
        nb = nb / 16;
        len++;
    }
    return len;
}

int fx_puller(va_list *args, buffer_t *buf, flag_state_t *st)
{
    unsigned int nb = va_arg(*args, unsigned int);
    int len = hex_len(nb);
    char *str = unpeutout_hex(nb, len);
    int ret;
    char const *prefix = "";

    if (str == NULL)
        return -1;
    if (st->hash && nb != 0)
        prefix = "0x";
    ret = emit_number(buf, st, prefix, str);
    free(str);
    return ret;
}
