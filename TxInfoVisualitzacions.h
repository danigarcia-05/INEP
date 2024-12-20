#pragma once
#ifndef TXINFOVISUALITZACIONS_HPP
#define TXINFOVISUALITZACIONS_HPP
#include "PassarelaUsuari.h"
#include "CercadoraVisualitzaPel.h"
#include "CercadoraVisualitzaSerie.h"
#include "PassarelaVisualitzaSerie.h"
#include "PassarelaVisualitzaPel.h"
using namespace std;
#include <iostream>
#include <unistd.h>
#include <string>
#include <stdexcept> 
#include <utility>

class TxInfoVisualitzacions {
public:
    struct Resultat {
        int _numVisualitzacioPelicula;
        int _numVisualitzacioSerie;
    };


    TxInfoVisualitzacions();

    Resultat obteResultat() const;

private:
    int _numVisualitzacioPelicula;
    int _numVisualitzacioSerie;
};


#endif
