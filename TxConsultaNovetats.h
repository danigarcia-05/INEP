#ifndef TXCONSULTANOVETATS_HPP
#define TXCONSULTANOVETATS_HPP
#pragma once
#include "CercadoraPelicula.h"
#include "CercadoraContingut.h"
#include "CercadoraModalitat.h"
#include "CercadoraCapitol.h"
#include "DTOPelicula.h"
#include "PassarelaPelicula.h"
#include "PassarelaCapitol.h"
#include "DTOPelicula.h"
#include "DTOCapitol.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>  
#include <vector>

class TxConsultaNovetats {
private:
    vector<DTOPelicula> _pelicules;
    vector<DTOCapitol> _capitols;    
public:
    TxConsultaNovetats();
    ~TxConsultaNovetats();
    
    void executar(string mod);
    vector<DTOPelicula> obtePelicules();
    vector<DTOCapitol> obteCapitols();
};

#endif

