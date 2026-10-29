#include "my.h"

double abs_rounded(double n, int precision)
{
    double nb = n;
    double half = 0.5;

    if (nb < 0)
        nb = -nb;
    if (precision < 0)
        return nb;
    for (int i = 0; i < precision; i++)
        half = half / 10;
    return nb + half;
}

double get_absf(double n)
{
    return abs_rounded(n, -1);
}
