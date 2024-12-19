#ifndef UTILS_H
#define UTILS_H

#include <termios.h>
#include <unistd.h>

namespace utils {
    // Desactiva el eco de la terminal
    inline void desactivarEco() {
        struct termios t;
        tcgetattr(STDIN_FILENO, &t);  // Obtener configuración actual de la terminal
        t.c_lflag &= ~ECHO;           // Desactivar eco
        tcsetattr(STDIN_FILENO, TCSANOW, &t);  // Aplicar la nueva configuración
    }

    // Reactiva el eco de la terminal
    inline void activarEco() {
        struct termios t;
        tcgetattr(STDIN_FILENO, &t);  // Obtener configuración actual de la terminal
        t.c_lflag |= ECHO;            // Activar eco
        tcsetattr(STDIN_FILENO, TCSANOW, &t);  // Aplicar la nueva configuración
    }
}

#endif 
