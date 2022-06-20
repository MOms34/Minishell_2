/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_strncmp
*/

int my_strlen(char const *str);

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (my_strlen(s1) < n || my_strlen(s2) < n)
        return (1);
    for (int i = 0; n > 0; i++, n--) {
        if (s1[i] != s2[i])
            return (1);
    }
    return (0);
}
