#ifndef CERCADORAPELICULA_HPP
#define CERCADORAPELICULA_HPP
#pragma once
#include "PassarelaPelicula.h"
#include <vector>
#include <stdexcept>

class CercadoraPelicula {
private:

    CercadoraPelicula();

public:
    
    static CercadoraPelicula& getInstance();

    PassarelaPelicula cercaPelicula(string titolP);
    vector<PassarelaPelicula> cercaPeliculesRelacionades(string titolP);
    vector<PassarelaPelicula> cercaPeliculesMesVistes();
    vector<PassarelaPelicula> cercaNovesEstrenes(string mod);
    vector<PassarelaPelicula> cercaProperesEstrenes(string mod);

    ~CercadoraPelicula();
};
#endif
