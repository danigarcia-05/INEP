#ifndef UTILS_H
#define UTILS_H

#include <windows.h>
#include <string>
using namespace std;

namespace utils {
    // Desactiva el eco de la consola
    inline void desactivarEco();

    // Reactiva el eco de la consola
    inline void activarEco();

    string convertirData(string dia, string mes, string any);
}
#endif



