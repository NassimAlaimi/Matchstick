/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-nassim.alaimi
** File description:
** loop_2
*/

#include "my.h"

void check_win(matchstick_s *m, int player)
{
    int s;

    for (int i = 0; i <= m->h-2; i++)
        s+=m->map[i];
    if (player == 1 && s == 0)
        m->status = -1;
    else if (player == 2 && s == 0)
        m->status = 1;
}

void print_remov(char *str, int lines, int matches)
{
    my_putstr(str);
    my_putstr(" removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(lines);
    my_putchar('\n');
}

void remove_stick(matchstick_s *matchstick, int lines, int m)
{
    matchstick->map[lines] -= m;
}

int check_m_turn(matchstick_s *matchstick, int lines, int m)
{
    if (m > matchstick->max) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(matchstick->max);
        my_putstr(" matches per turn\n");
        return (0);
    }
    if (matchstick->map[lines-1]-m < 0) {
        my_putstr("Error: not enough matches on this line\n");
        return (0);
    }
    if (m < 1) {
        my_putstr("Error: you have to remove at least one match\n");
        return (0);
    }
    return (1);
}

int check_l_turn(matchstick_s *m, int lines)
{
    if (lines - 1 > m->h - 2 || lines == 0) {
        my_putstr("Error: this line is out of range\n");
        return (0);
    }
    return (1);
}