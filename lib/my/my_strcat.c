/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** strcat
*/

#include <stdlib.h>
int my_strlen(char const *str);
int my_strcpy(char *dest, char const *src);

char *my_strcat(char *dest, char const *src)
{
    int size_f = my_strlen(src) + my_strlen(dest);
    int dest_size = my_strlen(dest);
    int i;
    char *temp = malloc(sizeof(char) * (dest_size) + 1);

    my_strcpy(temp, dest);
    dest = malloc(sizeof(char) * (size_f + 2));
    for (i = 0; temp[i] != '\0'; i++) {
        dest[i] = temp[i];
    }
    for (int j = 0; src[j] != '\0'; i++, j++) {
        dest[i] = src[j];
    }
    dest[i] = '\0';
    return dest;
}
