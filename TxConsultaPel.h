#ifndef CONSULTAPEL_HPP
#define CONSULTAPEL_HPP
#pragma once
#include "PassarelaVisualitzaPel.h"
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