#ifndef TXREGISTRAUSUARI_HPP
#define TXREGISTRAUSUARI_HPP
#pragma once
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;
#include "PassarelaUsuari.h"


class TxRegistraUsuari {
private:

    string _nomU;
    string _sobrenomU;
    string _contrasenyaU;
    string _correuElectronicU;
    string _dataNaixement;
    string _modalitatSubscripcio;

public:
    
    TxRegistraUsuari(string nU, string sU, string cU, string ceU, string dnU, string msU);

    void executar();
};

#endif