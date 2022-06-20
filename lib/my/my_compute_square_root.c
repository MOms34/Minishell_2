/*
** EPITECH PROJECT, 2021
** my_compute_square_root
** File description:
** .
*/

int my_compute_square_root(int nb);

int my_square(int nb, int i)
{
    if (nb < 0)
        nb = nb * -1;
    if (nb == 0)
        return (0);
    if ((nb / i) == i)
        return (i);
    return (my_square(nb, i + 1));
}

int my_compute_square_root(int nb)
{
    return (my_square(nb, 1));
}
