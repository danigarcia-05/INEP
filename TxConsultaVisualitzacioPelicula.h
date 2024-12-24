#ifndef CONSULTAVISUALITZACIOPELICULA_HPP
#define CONSULTAVISUALITZACIOPELICULA_HPP
#pragma once
#include "PassarelaVisualitzaPel.h"
#include "DTOVisualitzacioPelicula.h"
#include "CercadoraVisualitzaPel.h"
#include "PetitFlix.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>  

class TxConsultaVisualitzacioPelicula {
private:
    DTOVisualitzacioPelicula _resultat;
    PassarelaVisualitzaPel _pelicula;
public:
    TxConsultaVisualitzacioPelicula();
    void executar(string titolP);
    DTOVisualitzacioPelicula obteResultat();
    PassarelaVisualitzaPel obteVisualitzacioPelicula();
};

#endif
