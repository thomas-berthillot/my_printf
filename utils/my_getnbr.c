#include "my.h"
#include <stdbool.h>

static void check_type(int value, long *result, bool *overflow)
{
    int n = 0;

    if (*overflow)
        return;
    if ('0' <= value && value <= '9'){
        n = value - '0';
        *result = *result * 10 + n;
        if (*result > 2147483648){
            *overflow = true;
        }
    }
}

static void toggle_sign(int tmp_, bool *is_neg)
{
    if (tmp_ == '-'){
        *is_neg = !*is_neg;
    }
}

static int overflow_checker(long result, bool overflow)
{
    if (overflow || result > 2147483647 || result < -2147483648){
        return 0;
    }
    return 1;
}

static bool handle_char(int tmp, long *result, bool *overflow,
    bool *is_neg, bool *started)
{
    if ('0' <= tmp && tmp <= '9') {
        *started = true;
        check_type(tmp, result, overflow);
        return false;
    }
    if (!*started && (tmp == '-' || tmp == '+')) {
        toggle_sign(tmp, is_neg);
        return false;
    }
    return true;
}

static void parse_loop(char const *str, int len, long *result,
    bool *overflow, bool *is_neg)
{
    bool started = false;

    for (int i = 0; i < len; i++) {
        if (handle_char(str[i], result, overflow, is_neg, &started)) {
            break;
        }
    }
}

int my_getnbr(char const *str)
{
    int len = my_strlen(str);
    long result = 0;
    bool is_neg = false;
    bool overflow = false;

    parse_loop(str, len, &result, &overflow, &is_neg);
    if (is_neg) {
        result = result * -1;
    }
    if (overflow_checker(result, overflow) == 0) {
        return 0;
    }
    return result;
}
