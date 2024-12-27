#ifndef CONSULTAVISUALITZACIOCAPITOL_HPP
#define CONSULTAVISUALITZACIOCAPITOL_HPP
#pragma once
#include "PassarelaVisualitzaCapitol.h"
#include "CercadoraVisualitzaCapitol.h"
#include "PetitFlix.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>  

class TxConsultaVisualitzacioCapitol {
private:
    PassarelaVisualitzaCapitol _capitolVisualitzat;

public:
    TxConsultaVisualitzacioCapitol();
    void executar(string sobrenomU, string titolSerie, int numTemporada, int numero);
    PassarelaVisualitzaCapitol obteVisualitzacioCapitol();
};

#endif
