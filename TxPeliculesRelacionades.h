#ifndef PELICULESRELACIONADES_HPP
#define PELICULESRELACIONADES_HPP
#pragma once
#include "DTOPelicula.h"
#include "CercadoraPelicula.h"
#include "PetitFlix.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>  
#include <vector>  

class TxPeliculesRelacionades {
private:
    vector<DTOPelicula> _resultat;
    vector<PassarelaPelicula> _pelicula;
public:
    TxPeliculesRelacionades();
    void executar(string titolP);
    vector<DTOPelicula> obteResultat();
    vector<PassarelaPelicula> obtePelicula();
};

#endif


