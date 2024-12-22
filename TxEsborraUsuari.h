#ifndef TXESBORRAUSUARI_HPP
#define TXESBORRAUSUARI_HPP
#pragma once
#include "PetitFlix.h"
#include <stdexcept>  // Para runtime_error
#include <string>  // Para usar std::string
using namespace std;
#include <iostream>

class TxEsborraUsuari {
private:
    string _contraU; 

public:
    TxEsborraUsuari();
    TxEsborraUsuari(string contraU);

    void executar();
};

#endif
