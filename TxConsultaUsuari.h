#ifndef CONSULTAUSUARI_HPP
#define CONSULTAUSUARI_HPP
#pragma once
#include "PassarelaUsuari.h"
#include "DTOUsuari.h"
#include "PassarelaUsuari.h"
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
    void executar();
    DTOUsuari obteResultat();
    PassarelaUsuari obteUsuari();
};

#endif