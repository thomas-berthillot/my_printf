#include <unistd.h>
#include "my.h"

void my_puterr(char const *msg)
{
    if (msg == NULL)
        return;
    write(2, msg, my_strlen(msg));
}
