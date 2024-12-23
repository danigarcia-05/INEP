#ifndef CTRLMODIFICAUSUARI_HPP
#define CTRLMODIFICAUSUARI_HPP
#pragma once
#include "DTOUsuari.h"
#include "PassarelaUsuari.h"
#include "TxConsultaUsuari.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>

class CtrlModificaUsuari {
private:

    PassarelaUsuari _usuari;

public:

    CtrlModificaUsuari();

    DTOUsuari consultaUsuari();

    void modificaUsuari(string nomU, string contraU, string correuU, string neixU, string modalitatU);

    void modificaContrasenya(string contraU);

};
#endif