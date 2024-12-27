#pragma once
#ifndef TXINFOVISUALITZACIONS_HPP
#define TXINFOVISUALITZACIONS_HPP
#include "PassarelaUsuari.h"
#include "CercadoraVisualitzaPel.h"
#include "CercadoraVisualitzaCapitol.h"
#include "PassarelaVisualitzaPel.h"
#include "PetitFlix.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept> 
#include <utility>
#include <vector>

class TxInfoVisualitzacions {
public:
    TxInfoVisualitzacions();

    void executar();

    pair<int, int> obteResultat() const;

private:
    pair<int, int> _numVisualitzacions;
};


#endif
