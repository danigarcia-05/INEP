#ifndef CTRLVISUALITZAPELICULA_HPP
#define CTRLVISUALITZAPELICULA_HPP
#pragma once
#include "PassarelaVisualitzaPel.h"
#include "TxConsultaVisualitzacioPelicula.h"
#include "TxConsultaRelacionades.h"
#include "DTOPelicula.h"
#include "DTOVisualitzacioPelicula.h"
#include "TxConsultaPelicula.h"
#include "PetitFlix.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

class CtrlVisualitzaPelicula {
private:
    PassarelaVisualitzaPel _peliculaUsuari;
    string _sobrenom;
public:

    CtrlVisualitzaPelicula();

    DTOPelicula consultaPelicula(string titolP);
    void consultaPeliculaUsuari(string titolP);

    void modificaVisualitzacioPelicula(string titolP);

    vector<string> consultaRelacionades(string titolP);
};
#endif
