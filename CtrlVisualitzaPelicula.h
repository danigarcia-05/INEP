#ifndef CTRLMODIFICAUSUARI_HPP
#define CTRLMODIFICAUSUARI_HPP
#pragma once
#include "DTOPelicula.h"
#include "PassarelaPelicula.h"
#include "TxConsultaPelicula.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>

class CtrlVisualitzaPelicula {
private:

    PassarelaPelicula _pelicula;

public:

    CtrlVisualitzaPelicula();

    DTOPelicula consultaVisualitzacioPelicula();

    void modificaVisualitzacioPelicula(string sobrenomU, string titolP, string dataVisualitzacioU, string numVisualitzacionsU);
};
#endif
