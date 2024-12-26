#ifndef CONSULTATEMPORADES_HPP
#define CONSULTATEMPORADES_HPP
#pragma once
#include "DTOPelicula.h"
#include "CercadoraTemporada.h"
#include "PetitFlix.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>  

class TxConsultaPelicula {
private:
    DTOTemporada _resultat;
    PassarelaPelicula _pelicula;
    PassarelaContingut _contingut;

public:
    TxConsultaPelicula();
    void executar(string titolP);
    DTOPelicula obteResultat();
    PassarelaPelicula obtePelicula();
    PassarelaContingut obteContingut();
};

#endif

