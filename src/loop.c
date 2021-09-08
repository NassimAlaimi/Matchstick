/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-nassim.alaimi
** File description:
** loop
*/

#include <my.h>

char *ask_matches(matchstick_s *m)
{
    ssize_t matches = -1;
    size_t len = 0;
    char *input = NULL;

    my_putstr("Matches: ");
    matches = getline(&input, &len, stdin);
    if (matches == -1) {
        m->matches = 1;
        m->end = 1;
        return ("84");
    }
    m->matches = my_atoi(input);
    return (input);
}

char *ask_lines(matchstick_s *m)
{
    ssize_t lines = -1;
    size_t len = 0;
    char *input = NULL;

    my_putstr("Line: ");
    lines = getline(&input, &len, stdin);
    if (lines == -1) {
        m->lines = 1;
        m->end = 1;
        return ("84");
    }
    m->lines = my_atoi(input);
    return (input);
}

void player_turn_2(matchstick_s *m)
{
    if (check_input(ask_matches(m), m)==1 && m->end != 1) {
        if (check_m_turn(m, m->lines, m->matches) == 1 && m->end != 1)
            m->i=2;
    } else
        m->i=0;
}

int player_turn(matchstick_s *m)
{
    m->i = 0;
    my_putstr("\nYour turn:\n");
    while (m->i!=2) {
        if (m->end==1)
            return (84);
        else if (check_input(ask_lines(m), m)==1 && m->end != 1)
            m->i=1;
        if (m->i==1) {
            if (check_l_turn(m, m->lines) == 1 && m->end != 1) {
                player_turn_2(m);
            }
        }
    }
    remove_stick(m, m->lines-1, m->matches);
    print_remov("Player", m->lines, m->matches);
    check_win(m, 1);
    print_map(m->map_cpy, m->map, m->w, m->h);
    return (0);
}

int loop(matchstick_s *matchstick)
{
    while (matchstick->status == 0) {
        if (matchstick->status == 0)
            player_turn(matchstick);
        if (matchstick->end == 1)
            return (0);
        if (matchstick->status == 0 && matchstick->end !=1)
            ai_turn(matchstick);
    }
    if (matchstick->status == 1)
        my_putstr("I lost... snif... but I'll get you next time!!\n");
    if (matchstick->status == -1)
        my_putstr("You lost, too bad...\n");
    return (1);
}