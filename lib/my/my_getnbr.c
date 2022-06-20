/*
** EPITECH PROJECT, 2021
** getnbr
** File description:
** .
*/

int count(char const *str, int i, int o)
{
    long int nb = str[i] - 48;
    int cpt = 0;

    while (str[i] >= 48 && str[i] <= 57) {
        if (cpt > 0) {
            nb = nb * 10;
            nb = nb + (str[i] - 48);
        }
        if (nb > 2147483647)
            return (0);
        cpt = cpt + 1;
        i = i + 1;
    }
    if (o % 2 != 0)
        nb = nb * -1;
    return (nb);
}

int my_isalpha(char const *str, int i)
{
    if (str[i] <= 90 && str[i] >= 65)
        return (1);
    else if (str[i] <= 122 && str[i] >= 97)
        return (1);
    else
        return (0);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int k = 0;
    int o = 0;
    int nb;

    while (str[i] != '\0') {
        if (str[i] == '-')
            o = o + 1;
        if (my_isalpha(str, i) == 1)
            return (0);
        if (str[i] >= 48 && str[i] <= 57) {
            nb = count(str, i, o);
            return (nb);
        }
        i = i + 1;
    }
    return (0);
}
