#ifndef CERCADORAPELICULA_HPP
#define CERCADORAPELICULA_HPP
#pragma once
#include "PassarelaPelicula.h"
#include <vector>

class CercadoraPelicula {
private:

public:

    CercadoraPelicula();

    PassarelaPelicula cercaPelicula(string titolP);
    vector<PassarelaPelicula> cercaPeliculesRelacionades(string titolP);
    vector<PassarelaPelicula> cercaPeliculesMesVistes();
};
#endif
