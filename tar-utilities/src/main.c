#include "main.h"

int main(int argc, char *argv[]) {
    
    if (argc != 3) {
        puts("Usage: program `command` `tarname`");
        puts("Commands: l : list-tar, d : de-tar, m : mk-tar");
        return -1;
    }

    char command = argv[1][0];

    switch (command) {
        case 'l':
            return listar(argv[2]);
        case 'd':
            break;
        case 'm':
            break;
        default:
            puts("Usage: program `command` `tarname`");
            puts("Commands: list-tar, de-tar, mk-tar");
            return -1;
    }

    return 0;
}
