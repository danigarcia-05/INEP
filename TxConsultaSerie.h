#ifndef CONSULTAUSUARI_HPP
#define CONSULTAUSUARI_HPP
#pragma once
#include "DTOSerie.h"
#include "PassarelaVisualitzaSerie.h"
#include "PetitFlix.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>  

class TxConsultaSerie {
private:
    DTOUcapitol _resultat;
    PassarelaVisualitzaSerie _serie;
public:
    TxConsultaSerie();
    void executar();
    DTOUsuari obteResultat();
    PassarelaUsuari obteSerie();
};

#endif