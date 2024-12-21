#ifndef CONSULTAUSUARI_HPP
#define CONSULTAUSUARI_HPP  
#pragma once
#include "DTOUsuari.h"
#include "PassarelaUsuari.h"
#include "TxConsultaUsuari.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept> 
#include "Data.h"

class CtrlModificaUsuari {
private:

    PassarelaUsuari _usuari;

public:

    CtrlModificaUsuari();

    DTOUsuari consultaUsuari();
    
    void modificaUsuari(string nomU, string contraU, string correuU, Data neixU, string subsU);

};

#endif