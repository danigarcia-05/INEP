#ifndef CONSULTAPELICULA_HPP
#define CONSULTAPELICULA_HPP
#pragma once
#include "DTOPelicula.h"
#include "CercadoraPelicula.h"
#include "PetitFlix.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>  

class TxConsultaPelicula {
private:
    DTOPelicula _resultat;
    PassarelaPelicula _pelicula;
public:
    TxConsultaPelicula();
    void executar(string titolP);
    DTOPelicula obteResultat();
    PassarelaPelicula obtePelicula();
};

#endif

