/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-nassim.alaimi
** File description:
** print
*/

#include "my.h"

void print_l_space_1(int w, int *tcpy, int i)
{
    for (int y = 0; y < (w-tcpy[i])/2; y++)
        my_putchar(' ');
}

void print_l_space_2(int w, int *t, int i, int *tcpy)
{
    for (int y = 0; y < (w-tcpy[i])/2+tcpy[i]-t[i]; y++)
        my_putchar(' ');
}

void print_l_pipe(int *t, int i)
{
    for (int x = 0; x < t[i]; x++)
        my_putchar('|');
}

void print_ln(int h, int w, int *t, int *tcpy)
{
    for (int i = 0; i <= h - 2; i++) {
        my_putchar('*');
        print_l_space_1(w, tcpy, i);
        print_l_pipe(t, i);
        print_l_space_2(w, t, i, tcpy);
        my_putchar('*');
        my_putchar('\n');
    }
}

void print_map(int *tcpy, int *t, int w, int h)
{
    print_stars(w);
    print_ln(h, w, t, tcpy);
    print_stars(w);
}