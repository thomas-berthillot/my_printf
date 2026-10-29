#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

static char *zero_case(char *str)
{
    str[0] = '0';
    str[1] = '\0';
    return str;
}

static int fill_octal_digits(unsigned int nb, int *octalNum)
{
    int i = 0;

    for (i = 0; nb != 0; i++){
        octalNum[i] = nb % 8;
        nb = nb / 8;
    }
    return i;
}

static void fill_str(char *str, int *octalNum, int len)
{
    int a = 0;

    for (int y = len - 1; y >= 0; y--){
        str[a] = octalNum[y] + '0';
        a++;
    }
    str[len] = '\0';
}

char *unpeutout(unsigned int nb, int len)
{
    int octalNum[12];
    char *str = malloc(sizeof(char) * (len + 1));

    if (str == NULL)
        return NULL;
    if (nb == 0){
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    fill_octal_digits(nb, octalNum);
    fill_str(str, octalNum, len);
    return str;
}

int oct_len(unsigned int nb)
{
    int len = 0;

    if (nb == 0){
        return 1;
    }
    for (int i = 0; nb != 0; i++){
        nb = nb / 8;
        len++;
    }
    return len;
}

int fo_puller(va_list *args, buffer_t *buf, flag_state_t *st)
{
    unsigned int nb = va_arg(*args, unsigned int);
    int len = oct_len(nb);
    char *str = unpeutout(nb, len);
    int ret;
    char const *prefix = "";

    if (str == NULL)
        return -1;
    if (st->hash && st->precision <= len && (str[0] != '0'
            || st->precision == 0))
        prefix = "0";
    ret = emit_number(buf, st, prefix, str);
    free(str);
    return ret;
}
