/*
** EPITECH PROJECT, 2021
** stdarg.c
** File description:
** stdarg
*/

#include <stdarg.h>

int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);

int my_switch(char *s, int i, va_list list)
{
    switch (s[i]) {
    case 'c':
        my_putchar(va_arg(list, int));
        break;
    case 's':
        my_putstr(va_arg(list, char *));
        break;
    case 'd':
        my_put_nbr(va_arg(list, int));
        break;
    case 'i':
        my_put_nbr(va_arg(list, int));
        break;
    default:
        my_putchar(s[i]);
    }
    return 0;
}

int my_printf(char *s, ...)
{
    va_list list;
    int i = 0;

    va_start(list, s);
    while (i < my_strlen(s)) {
        if (s[i] == '%') {
            my_switch(s, i + 1, list);
            i = i + 1;
        } else {
            my_putchar(s[i]);
        }
        i = i + 1;
    }
    va_end(list);
}
