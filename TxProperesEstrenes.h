#ifndef TXPROPERESESTRENES_HPP
#define TXPROPERESESTRENES_HPP
#pragma once
#include "CercadoraPelicula.h"
#include "CercadoraCapitol.h"
#include "CercadoraContingut.h"
#include "DTOPelicula.h"
#include "DTOCapitol.h"
#include "PassarelaPelicula.h"
#include "PassarelaContingut.h"
#include "PassarelaCapitol.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>  
#include <vector>  

class TxProperesEstrenes {
private:
    vector<DTOPelicula> _pelicules;
    vector<DTOCapitol> _capitols;
public:
    TxProperesEstrenes();
    void executar(string mod);
    vector<DTOPelicula> obtePelicules();
    vector<DTOCapitol> obteCapitols();
};

#endif

