/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-nassim.alaimi
** File description:
** map
*/

#include <my.h>

int my_show_int_array(int *tab, int ac)
{
    if (ac < 0) {
        my_putchar('\n');
        return 0;
    }
    ac++;
    for (int i = 0; tab[i] != 0;i++) {
        my_put_nbr(tab[i]);
        if (tab[i] != 0)
            my_putchar(' ');
    }
    my_putchar('\n');
    return (0);
}

void make_map(matchstick_s *m, char **av, int ac)
{
    m->map = malloc(sizeof(int) * my_atoi(av[1])+1);
    m->map_cpy = malloc(sizeof(int) * my_atoi(av[1])+1);
    for (int i = 0; i <= my_atoi(av[1]); i++) {
        m->map[i] = 1 + 2 * i;
        m->map_cpy[i] = 1 + 2 * i;
    }
}