#ifndef TXINICISESSIO_HPP
#define TXINICISESSIO_HPP
#pragma once
#include <string>
#include "CercadoraUsuari.h"
#include "PassarelaUsuari.h"
#include "PetitFlix.h"
#include <stdexcept>
#include <iostream>
using namespace std;

class TxIniciSessio {
private:
    string _sobrenomU;
    string _contrasenyaU;

public:
    //Constructors
    TxIniciSessio(string sU, string cU);

    //Destructors
    ~TxIniciSessio();

    //Modificadors
    void executar();
};

#endif