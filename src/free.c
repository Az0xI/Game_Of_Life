/*
 * File that free all the ressources
 */

#include "gol.h"

void free_all_resources(win_t manager, char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);

    delwin(manager.b_game);
    delwin(manager.game);
}

