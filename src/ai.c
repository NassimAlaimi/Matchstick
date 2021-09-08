/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-nassim.alaimi
** File description:
** ai
*/

#include "my.h"

int check_input(char *s, matchstick_s *m)
{
    if (m->end == 1)
        return (84);
    for (int i = 0; s[i] != '\n'; i++) {
        if (my_is_number(s[i])==0) {
            my_putstr("Error: invalid input (positive number expected)\n");
            m->i = 0;
            return (0);
        }
    }
    return (1);
}

int check_ai_l_turn(matchstick_s *m, int lignes)
{
    if (lignes - 1 > m->h - 2 || lignes == 0)
        return (0);
    return (1);
}

int check_ai_m_turn(matchstick_s *matchstick, int lignes, int m)
{
    if (m > matchstick->max) {
        return (0);
    }
    if (matchstick->map[lignes-1]-m < 0) {
        return (0);
    }
    if (m < 1) {
        return (0);
    }
    return (1);
}

int ai_loop(int m, int lignes, matchstick_s *mat, int i)
{
    if (check_ai_m_turn(mat, lignes, m) == 1)
        i=1;
    return (i);
}

void ai_turn(matchstick_s *mat)
{
    time_t t;
    srandom((unsigned)time(&t));
    int lignes;
    int m;
    int i = 0;
    while (i!=1) {
        lignes = ((random()%(mat->h-1)+1));
        if (check_ai_l_turn(mat, lignes)==1) {
            m = ((random()%mat->max)+1);
            i = ai_loop(m, lignes, mat, i);
        }
    }
    my_putstr("\nAI's turn...\n");
    remove_stick(mat, lignes-1, m);
    print_remov("AI", lignes, m);
    print_map(mat->map_cpy, mat->map, mat->w, mat->h);
    check_win(mat, 2);
}