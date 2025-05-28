/*
** Headers file
*/

#ifndef GAME_OF_LIFE_H_
    #define GAME_OF_LIFE_H_

    #include <curses.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>
    #include <linux/limits.h>
    #include <time.h>

    #define DEFAULT_LENGHT 30
    #define DEFAULT_WIDTH 30
    #define LIVE 'X'
    #define TO_LIVE 'Y'
    #define DEAD '.'
    #define TO_DIE 'O'

typedef struct win_s {
    WINDOW *b_game;
    WINDOW *game;
    char *info;
} win_t;

// print the help message //
int print_help(void);

// Start the game //
int game_of_life(win_t *manager, char **map);

// Parse args and return a map //
char **parse_arg(int ac, char *argv[]);

// Visuals for the Game //
win_t init_win_manager(void);
void display_map(win_t *manager, char **map);

// Cleanup resources //
void free_all_resources(win_t manager, char **map);

#endif /* GAME_OF_LIFE_H_ */
