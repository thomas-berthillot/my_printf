int my_strlen(char const *str)
{
    int count = 0;

    while (*str != '\0'){
        str++;
        count++;
    }
    return count;
}
