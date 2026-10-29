#include "my.h"

void append_char(char *s, char c)
{
    size_t len = my_strlen(s);

    s[len] = c;
    s[len + 1] = '\0';
}
