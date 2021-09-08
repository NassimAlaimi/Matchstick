/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>


/* Struct */

typedef struct matchstick_t {
    int status;
    int w;
    int h;
    int *map;
    int *map_cpy;
    int max;
    int lines;
    int matches;
    int end;
    int i;
} matchstick_s;

/* LIB FUNCTIONS */

int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_isneg(int n);
int my_put_nbr(int nb);
void my_putchar(char c);
void my_putstr(char const *str);
void my_swap(int a, int b);
char *my_strupcase(char *str);
int word_check(char *str, char const *to_find, int i, char **sub_ptr);
char *my_strncpy(char *dest, char const *src, int n);
int my_strncmp(char const *s1, char const *s2, size_t n);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char const *src);
char *my_strcapitalize(char *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *array, int size);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_atoi(const char *nptr);
int my_show_word_array(char **tab);
int my_array_len(char **array);
char *my_int_to_str(int nb);
int my_is_number(char c);
char *my_strdup(char const *src);
int my_is_char_in_str(char c, char *str);

/* Project Fonction */

int loop(matchstick_s *matchstick);
void make_map(matchstick_s *m, char **av, int ac);
void print_map(int *tcpy, int *t, int w, int h);
int my_show_int_array(int *tab, int ac);
void print_stars(int w);
int check_l_turn(matchstick_s *m, int lignes);
int check_m_turn(matchstick_s *matchstick, int lignes, int m);
void print_remov(char *str, int lines, int matches);
void remove_stick(matchstick_s *matchstick, int lignes, int m);
void check_win(matchstick_s *m, int player);
void ai_turn(matchstick_s *mat);
int check_input(char *s, matchstick_s *m);
#endif /* !MY_H_ */
