/*
** EPITECH PROJECT, 2021
** strncat
** File description:
** strncat
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int size_dest = my_strlen(dest);
    int size_src = my_strlen(src);
    int i = 0;

    while (i != nb) {
        dest[size_dest + i] = src[i];
        i = i + 1;
    }
    dest[size_dest + i] = '\0';
    return (dest);
}
