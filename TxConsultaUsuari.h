#ifndef TXCONSULTAUSUARI_HPP
#define TXCONSULTAUSUARI_HPP
#pragma once
#include "PassarelaUsuari.h"
#include "DTOUsuari.h"
#include "PetitFlix.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>  

class TxConsultaUsuari {
private:
    DTOUsuari _resultat;
    PassarelaUsuari _usuari;
public:
    TxConsultaUsuari();
    bool executar();
    DTOUsuari obteResultat();
    PassarelaUsuari obteUsuari();
    ~TxConsultaUsuari();
    
};

#endif