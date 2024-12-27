#ifndef TXCONSULTAVISUALITZACIOCAPITOL_HPP
#define TXCONSULTAVISUALITZACIOCAPITOL_HPP
#pragma once
#include "PassarelaVisualitzaCapitol.h"
#include "CercadoraVisualitzaCapitol.h"
#include "DTOVisualitzacioCapitol.h"
#include "PetitFlix.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>  

class TxConsultaVisualitzacioCapitol {
private:
    PassarelaVisualitzaCapitol _capitolVisualitzat;
    DTOVisualitzacioCapitol _resultat;

public:
    TxConsultaVisualitzacioCapitol();
    void executar(string sobrenomU, string titolSerie, int numTemporada, int numero);
    PassarelaVisualitzaCapitol obteVisualitzacioCapitol();
    DTOVisualitzacioCapitol obteResultat();
};

#endif
