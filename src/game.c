/*
 * File that handle all the computing
 */

#include "gol.h"

static void process_changes(char **map, int i, int j)
{
    int nb_neigh = map[i][j] == DEAD ? 0 : -1;
    int x = i <= 0 ? 0 : i - 1;
    int y = j <= 0 ? 0 : j - 1;

    // Check for neighbour and error handling
    for (; x <= i + 1 && map[x] != NULL; x++) {
        for (; y <= j + 1 && map[x][y] != '\0'; y++)
            if (map[x][y] == LIVE || map[x][y] == TO_DIE) nb_neigh++;
        y = j <= 0 ? 0 : j - 1;
    }

    // Modify array with the game rules
    if (nb_neigh < 2 || nb_neigh > 3) if (map[i][j] == LIVE) map[i][j] = TO_DIE;
    if (nb_neigh == 3) map[i][j] = TO_LIVE;
}

static void handle_user_input(int input)
{
    switch (input) {
    case ' ':
        break;
    }
}

int game_of_life(win_t *manager, char **map)
{
    clock_t d_time = 1000000;
    clock_t time = clock();
    int input;

    // Game loop
    while (true) {
        input = getch();
        if (input == 'q')
            break;
        handle_user_input(input);
        display_map(manager, map);
        if (clock() - time > d_time) {
            for (int i = 0; map[i] != NULL; i++) {
                for (int j = 0; map[i][j] != '\0'; j++)
                    process_changes(map, i, j);
            }
            time = clock();
        }
    }
    return 0;
}
