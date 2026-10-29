#include "my.h"

char *e_for_0(char *str)
{
    str[0] = '0';
    str[1] = '.';
    str[2] = '0';
    str[3] = '0';
    str[4] = '0';
    str[5] = '0';
    str[6] = '0';
    str[7] = '0';
    str[8] = 'e';
    str[9] = '+';
    str[10] = '0';
    str[11] = '0';
    return str;
}

void fill_exposant(char *str, int exp)
{
    str[0] = 'e';
    if (exp >= 0) {
        str[1] = '+';
    } else {
        str[1] = '-';
    }
    exp = get_abs_int(exp);
    str[2] = exp / 10 + '0';
    str[3] = exp % 10 + '0';
}
