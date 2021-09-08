/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-nassim.alaimi
** File description:
** main
*/

#include <my.h>

int check_error(int ac, char **av)
{
    if (ac < 3) {
        write(2, "Error : not enough arguments.\n", 30);
        return (-1);
    } else if (ac > 3) {
        write(2, "Error : too few arguments.\n", 27);
        return (-1);
    } else if (my_str_isnum(av[1]) == 0 || my_str_isnum(av[2]) == 0) {
        write(2, "Error : invalid number.\n", 25);
        return (-1);
    } else if (!(my_atoi(av[1]) > 1 && my_atoi(av[1]) < 100)) {
        write(2, "Error : invalid number.\n", 25);
        return (-1);
    } else if (my_atoi(av[2]) <= 0) {
        write(2, "Error : invalid number.\n", 25);
        return (-1);
    }
    return (0);
}

int main(int ac, char **av)
{
    matchstick_s matchstick;

    if (check_error(ac, av) == -1)
        return (84);
    matchstick.h = my_atoi(av[1])+1;
    matchstick.w = my_atoi(av[1])*2;
    matchstick.max = my_atoi(av[2]);
    matchstick.status = 0;
    matchstick.i = 0;
    matchstick.end = 0;
    make_map(&matchstick, av, ac);
    print_map(matchstick.map_cpy, matchstick.map, matchstick.w, matchstick.h);
    if (loop(&matchstick)==0)
        return (0);
    if (matchstick.status==-1)
        return (2);
    if (matchstick.status==1)
        return (1);
}