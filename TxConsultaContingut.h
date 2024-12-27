#ifndef TXCONSULTACONTINGUT_HPP
#define TXCONSULTACONTINGUT_HPP
#pragma once
#include "DTOContingut.h"
#include "CercadoraContingut.h"
#include "PassarelaContingut.h"
#include "PetitFlix.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>  
#include <vector>

class TxConsultaContingut {
private:
    DTOContingut _resultat;
    PassarelaContingut _contingut;
public:
    TxConsultaContingut();
    void executar(string titolC);
    DTOContingut obteResultat();
    PassarelaContingut obteContingut();
};

#endif


