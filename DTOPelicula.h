#ifndef DTOPELICULA_HPP
#define DTOPELICULA_HPP
#pragma once
#include <string>
using namespace std;
#include "PassarelaPelicula.h"

class DTOPelicula {
public:

    DTOPelicula();
    DTOPelicula(string titolP, string descripcioP, string  qualificacioP, string dataP, int duracioP, string tipusP, int visGlobals, string subscripcio);
    ~DTOPelicula();

    //GETTERS
    string obteTitol() const;
    string obteDescripcio() const;
    string obteQualificacio() const;
    string obteDataP() const;
    int obteDuracio() const;
    string obteTipus() const;
    int obteVisualitzacionsGlobals() const;
    string obteSubscripcio() const;

    //SETTERS
    void setTitol(string titol);
    void setDescripcio(string descripcio);
    void setQualificacio(string qualificacio);
    void setDataP(string data);
    void setDuracio(int duracio);
    void setTipus(string tipus);
    void setVisualitzacionsGlobals(int visGlobals);
    void setSubscripcio(string subscripcio);

    DTOPelicula& operator=(const DTOPelicula& obj);

private:
    string _titol;
    string _descripcio;
    string _qualificacio;
    string _data;
    int _duracio;  
    string _tipus;
    int _visGlobals;
    string _subscripcio;
};
#endif
