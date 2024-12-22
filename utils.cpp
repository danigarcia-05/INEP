#include "utils.h"

    // Desactiva el eco de la consola
    inline void utils::desactivarEco() {
        HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
        DWORD mode;
        GetConsoleMode(hStdin, &mode);
        SetConsoleMode(hStdin, mode & ~ENABLE_ECHO_INPUT);
    }

    // Reactiva el eco de la consola
    inline void utils:: activarEco() {
        HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
        DWORD mode;
        GetConsoleMode(hStdin, &mode);
        SetConsoleMode(hStdin, mode | ENABLE_ECHO_INPUT);
    }

    string utils::convertirData(string dia, string mes, string any) {
        return any + "-" + mes + "-" + dia;
    }





