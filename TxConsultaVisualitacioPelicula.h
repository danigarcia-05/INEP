#ifndef CONSULTAUSUARI_HPP
#define CONSULTAUSUARI_HPP
#pragma once
#include "PassarelaVisualitzaPel.h"
#include "DTOPelicula.h"
#include "PetitFlix.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>  

//A MITGES

class TxConsultaVisualitzacioPelicula {
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