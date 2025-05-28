/*
 * Main file
 */

#include "gol.h"

win_t init_win_manager(void)
{
    win_t manager = {0};

    manager.b_game = subwin(stdscr, LINES - 1, COLS, 0, 0);
    box(manager.b_game, ACS_VLINE, ACS_HLINE);
    manager.game = subwin(stdscr, LINES - 3, COLS - 2, 1, 1);
    manager.info = "Quit: <q>";
    return manager;
}

void display_map(win_t *manager, char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            if (map[i][j] == TO_DIE) map[i][j] = DEAD;
            if (map[i][j] == TO_LIVE) map[i][j] = LIVE;
        }
        mvwprintw(manager->game, i, 0, "%s", map[i]);
    }
    mvprintw(LINES - 1, 0, "%s", manager->info);

    wrefresh(manager->b_game);
    wrefresh(manager->game);
    wrefresh(stdscr);
}
