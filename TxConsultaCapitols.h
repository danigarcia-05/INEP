#ifndef TXCONSULTACAPITOLS_HPP
#define TXCONSULTACAPITOLS_HPP
#pragma once
#include "CercadoraCapitol.h"
#include "PassarelaCapitol.h"
#include "PetitFlix.h"
#include "DTOCapitol.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>  

class TxConsultaCapitols {
private:
   vector<DTOCapitol> _resultat;
   vector<PassarelaCapitol> _capitols;

public:
    TxConsultaCapitols();
    void executar(string titolS, int numTemporada);
    vector<DTOCapitol> obteResultat();
    vector<PassarelaCapitol> obteCapitols();
};

#endif

