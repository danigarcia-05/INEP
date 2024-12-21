#ifndef UTILS_H
#define UTILS_H

#include <windows.h>
#include <string>

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

    string convertirData(dia, mes, any) {
        return any + "-" + mes + "-" + dia;
    }
}
#endif
