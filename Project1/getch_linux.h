#ifndef GETCH_LINUX_H
#define GETCH_LINUX_H

#ifdef __linux__
#include <termios.h>
#include <unistd.h>

inline int _getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#else
#include <conio.h>
#endif

#endif
