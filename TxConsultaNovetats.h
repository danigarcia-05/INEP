#ifndef CONSULTANOVETATS_HPP
#define CONSULTANOVETATS_HPP
#pragma once
#include "CercadoraPelicula.h"
#include "CercadoraContingut.h"
#include "CercadoraCapitol.h"

#include "DTOPelicula.h"
#include "PassarelaPelicula.h"
#include "PassarelaCapitol.h"
#include "DTOPelicula.h"
#include "DTOCapitol.h"
#include "PetitFlix.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>  

class TxConsultaNovetats {
private:
    vector<DTOPelicula> _pelicules;
    vector<DTOCapitol> _capitols;    
public:
    TxConsultaNovetats();
    void executar(string mod);
    vector<DTOPelicula> obtePelicules();
    vector<DTOCapitol> obteCapitols();
};

#endif

