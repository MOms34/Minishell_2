/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** strcpy
*/

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    int j = my_strlen(src);

    while (j >= 0) {
        dest[i] = src[i];
        j = j - 1;
        i = i + 1;
    }
    return (dest);
}
