#ifndef TXCONSULTACAPITOLS_HPP
#define TXCONSULTACAPITOLS_HPP
#pragma once
#include "CercadoraCapitol.h"
#include "PetitFlix.h"
#include "DTOCapitol.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>  

class TxConsultaCapitols {
private:
   vector<DTOCapitol> _capitols;

public:
    TxConsultaCapitols();
    void executar(string titolS, int numTemporada);
    vector<DTOCapitol> obteResultat();

};

#endif

