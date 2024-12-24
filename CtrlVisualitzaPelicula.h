#ifndef CTRLVISUALITZAPELICULA_HPP
#define CTRLVISUALITZAPELICULA_HPP
#pragma once
#include "PassarelaVisualitzaPel.h"
#include "TxConsultaVisualitzacioPelicula.h"
#include "DTOPelicula.h"
#include "TxConsultaPelicula.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

class CtrlVisualitzaPelicula {
private:

    PassarelaPelicula _pelicula;
    PassarelaVisualitzaPel _peliculaUsuari;
    PassarelaUsuari _usuari;

public:

    CtrlVisualitzaPelicula();

    DTOPelicula consultaPelicula(string titolP);

    void modificaVisualitzacioPelicula(string titolP);

    vector<DTOPelicula> consultaPeliculesRelacionades(string titolP);
};
#endif
