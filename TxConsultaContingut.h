#ifndef TXCONSULTACONTINGUT_HPP
#define TXCONSULTACONTINGUT_HPP
#pragma once
#include "DTOPelicula.h"
#include "CercadoraContingut.h"
#include "PetitFlix.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>  

class TxConsultaContingut {
private:
    DTOPelicula _resultat;
    PassarelaContingut _pelicula;
public:
    TxConsultaContingut();
    void executar(string titolC);
    DTOPelicula obteResultat();
    PassarelaContingut obtePelicula();
};

#endif


