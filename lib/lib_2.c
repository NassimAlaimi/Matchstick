/*
** EPITECH PROJECT, 2020
** my_str_isalpha.c
** File description:
** function that returns if the string contains alphabetical characters
*/

#include "my.h"

char *my_strcpy(char *dest, char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++)
        dest[i] = str[i];
    dest[i] = '\0';
    return (dest);
}

char *my_strlowcase(char *str)
{
    int i;

    for (i = 0; i < my_strlen(str); i += 1) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
    return (str);
}

int my_atoi(char *nbr)
{
    int res = 0;

    for (int i = 0; nbr[i] != '\0'; i++) {
        res = (res * 10) + (nbr[i] - '0');
    }
    return (res);
}

int my_str_isnum(char const *str)
{
    if (str[0] == '-')
       return (0); 
    for (int i = 0; str[i] != '\0';) {
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return (0);
    }
    return (1);
}

char *my_strdup(char const *src)
{
    char *ret;

    ret = malloc(sizeof(char) * (my_strlen(src)+1));
    ret = my_strcpy(ret, src);
    return (ret);
}