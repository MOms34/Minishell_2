/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** put_nbr
*/

#include <unistd.h>

void my_putchar(char c);
int my_put_nbr(int nb);

int my_display(int a)
{
    my_putchar('-');
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

int test_positive(int nb, int digits)
{
    if (nb > 9) {
        digits = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(digits + 48);
    } else {
        my_putchar(nb % 10 + 48);
    }
}

int my_put_nbr(int nb)
{
    int digits;
    if (nb == -2147483648) {
        my_display(digits);
    } else {
        if (nb < 0) {
            my_putchar('-');
            nb = nb * -1;
        }
        if (nb >= 0) {
            test_positive(nb, digits);
        }
    }
}
