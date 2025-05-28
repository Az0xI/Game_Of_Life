/*
 * Main file
 */

#include "gol.h"

int main(int ac, char *argv[])
{
    if (ac == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0))
        return print_help();

    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, true);
    curs_set(0);
    keypad(stdscr, TRUE);

    win_t manager = init_win_manager();
    char **map = parse_arg(ac, argv); if (map == NULL) return -1;
    game_of_life(&manager, map);

    free_all_resources(manager, map);
    endwin();
    return 0;
}
