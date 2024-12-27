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
    DTOVisualitzacioPelicula _pelVis;

public:
    TxConsultaVisualitzacioPelicula();
    void executarVP(string usuari);
    void executarPelVis(string titolP, string usuari);
   
    PassarelaVisualitzaPel obteVisualitzacioPelicula();
    DTOVisualitzacioPelicula obteResultatSingle();
    vector<PassarelaVisualitzaPel> obteConjuntVisualitzacionsPelicules();
    vector<DTOVisualitzacioPelicula> obteResultat();
};

#endif
