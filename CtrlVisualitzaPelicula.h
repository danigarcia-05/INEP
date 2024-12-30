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
#include "utils.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

class CtrlVisualitzaPelicula {
private:

    PassarelaVisualitzaPel _peliculaUsuari;
    PassarelaPelicula _infoP;
    PassarelaContingut _infoC;
    vector<DTOPelicula> _resultat;
    PassarelaUsuari _usuari;
    
public:

    CtrlVisualitzaPelicula();
    ~CtrlVisualitzaPelicula();

    DTOPelicula consultaPelicula(string titolP);
    string consultaPeliculaUsuari(string titolP);

    void modificaVisualitzacioPelicula(string titolP, string sobrenom);

    void consultaRelacionades(string titolP);
    vector<DTOPelicula> obteResultat();
};
#endif
