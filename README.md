# my_sokoban

The my_sokoban project is a game playable in the terminal thanks to the ncurses library

This project consist to store boxes in their storages points

'#' is wall
'P' is player
'O' for storage point
'X' for box

If all boxes are on storage locations, the player wins and the program must return 0.

Otherwise, if none of the boxes can be moved anymore, he loses and the program must return 1.
The game must be reset by pressing the space bar.
Redimensioning the terminal must be handled. As long as the terminal is too small to display the whole
map, a centered message, asking the user to enlarge the terminal, must be displayed.
The game must be able to be played with the arrow keys (LEFT, RIGHT, UP and DOWN).
A valid map can only contains the characters SPACE, ‘\n’, ‘#’, ‘X’, ‘O’ and ‘P’.
If an invalid map is supplied, the program must exit with an error.

Compilation:
    make re

Unit test:
    make tests_run

USAGE:
    execute binary with -h option