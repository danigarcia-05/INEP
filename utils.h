#ifndef UTILS_H
#define UTILS_H

#include <windows.h>

namespace utils {
    // Desactiva el eco de la consola
    inline void desactivarEco() {
        HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
        DWORD mode;
        GetConsoleMode(hStdin, &mode);
        SetConsoleMode(hStdin, mode & ~ENABLE_ECHO_INPUT);
    }

    // Reactiva el eco de la consola
    inline void activarEco() {
        HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
        DWORD mode;
        GetConsoleMode(hStdin, &mode);
        SetConsoleMode(hStdin, mode | ENABLE_ECHO_INPUT);
    }
}
#endif
