#ifndef CTRLMODIFICAUSUARI_HPP
#define CTRLMODIFICAUSUARI_HPP
#pragma once
#include "PassarelaVisualitzaPel.h"
#include "TxConsultaPelicula.h"
#include "DTOVisualitzacioPelicula.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>

class CtrlVisualitzaPelicula {
private:

    PassarelaVisualitzaPel _pelicula;

public:

    CtrlVisualitzaPelicula();

    DTOVisualitzacioPelicula consultaVisualitzacioPelicula();

    void modificaVisualitzacioPelicula();
};
#endif
