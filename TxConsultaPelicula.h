#ifndef TXCONSULTAPELICULA_HPP
#define TXCONSULTAPELICULA_HPP
#pragma once
#include "DTOPelicula.h"
#include "CercadoraPelicula.h"
#include "CercadoraContingut.h"
#include "PassarelaPelicula.h"
#include "PassarelaContingut.h"
#include "PetitFlix.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>  

class TxConsultaPelicula {
private:
    DTOPelicula _resultat;
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

