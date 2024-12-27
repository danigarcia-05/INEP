#ifndef DTOCONTINGUT_HPP
#define DTOCONTINGUT_HPP
#pragma once
#include <string>
using namespace std;
#include "PassarelaContingut.h"

class DTOContingut {
private:
    string _titol;
    string _descripcio;
    string _qualificacio;
    string _tipus;
public:

    DTOContingut();
    DTOContingut(string titol, string descripcio, string qualificacio, string tipus);

    //GETTERS
    string obteTitol();
    string obteDescripcio();
    string obteQualificacio();
    string obteTipus();
    
    //SETTERS
    void setTitol(string titol);
    void setDescripcio(string descripcio);
    void setQualificacio(string qualificacio);
    void setTipus(string tipus);

    DTOContingut& operator=(const DTOContingut& obj);
};
#endif
