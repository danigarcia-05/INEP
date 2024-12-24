#ifndef DTOPELICULA_HPP
#define DTOPELICULA_HPP
#pragma once
#include <string>
using namespace std;
#include "PassarelaPelicula.h"

class DTOPelicula {
public:

    DTOPelicula();
    DTOPelicula(string titolP, string descripcioP, string  qualificacioP, string dataP, int duracioP, string tipusP);

    //GETTERS
    string obteTitol();
    string obteDescripcio();
    string obteQualificacio();
    string obteDataP();
    int obteDuracio();
    string obteTipus();

    //SETTERS
    void setTitol(string titol);
    void setDescripcio(string descripcio);
    void setQualificacio(string qualificacio);
    void setDataP(string data);
    void setDuracio(int duracio);
    void setTipus(string tipus);

    DTOPelicula& operator=(const DTOPelicula& obj);

private:
    string _titol;
    string _descripcio;
    string _qualificacio;
    string _data;
    int _duracio;
    string _tipus;
};
#endif
