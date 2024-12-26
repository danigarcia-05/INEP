#ifndef CONSULTATEMPORADES_HPP
#define CONSULTATEMPORADES_HPP
#pragma once
#include "DTOPelicula.h"
#include "CercadoraTemporada.h"
#include "PetitFlix.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>  

class TxConsultaTemporada {
private:
    PassarelaTemporada _temporada;

public:
    TxConsultaTemporades();
    void executar(string titolT);
    DTOPelicula obteResultat();
    PassarelaTemporada obteTemporada();
};

#endif

