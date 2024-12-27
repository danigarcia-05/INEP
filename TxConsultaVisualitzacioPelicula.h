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
    PassarelaVisualitzaPel _peliculaV;
    vector<DTOVisualitzacioPelicula> _resultat;
    vector<PassarelaVisualitzaPel> _cjVisualitzacioPelicula;
    DTOVisualitzacioPelicula 

public:
    TxConsultaVisualitzacioPelicula();
    void executar(string titolP, string usuari);
    void executarVP(string usuari);
   
    PassarelaVisualitzaPel obteVisualitzacioPelicula();
    vector<PassarelaVisualitzaPel> obteConjuntVisualitzacionsPelicules();
    vector<DTOVisualitzacioPelicula> obteResultat();
};

#endif
