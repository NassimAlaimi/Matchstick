/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-nassim.alaimi
** File description:
** print_2
*/

#include "my.h"

void print_stars(int w)
{
    for (int i = 0; i < w + 1; i++) {
        my_putchar('*');
    }
    my_putchar('\n');
}