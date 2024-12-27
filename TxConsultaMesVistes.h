#ifndef CONSULTAMESVISTES_HPP
#define CONSULTAMESVISTES_HPP
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

class TxConsultaMesVistes {
private:
    vector<DTOPelicula> _resultat;
    vector<PassarelaPelicula> _cjPP;    
public:
    TxConsultaMesVistes();
    void executar();
    vector<DTOPelicula> obteResultat();
    vector<PassarelaPelicula> obtePelicules();
};

#endif

