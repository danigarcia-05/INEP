#ifndef TXPROPERESESTRENES_HPP
#define TXPROPERESESTRENES_HPP
#pragma once
#include "CercadoraPelicula.h"
#include "CercadoraCapitol.h"
#include "CercadoraModalitat.h"
#include "CercadoraContingut.h"
#include "DTONovetat.h"
#include "PassarelaPelicula.h"
#include "PassarelaContingut.h"
#include "PassarelaCapitol.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>  
#include <vector>  
#include <locale>

class TxProperesEstrenes {
private:
    vector<DTONovetat> _resultat;

public:
    TxProperesEstrenes();
    void executar(string mod);
    vector<DTONovetat> obteResultat();
    ~TxProperesEstrenes();
};

#endif

