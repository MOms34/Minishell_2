/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** function lib
*/

#include "minishell.h"

int my_isalpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}
