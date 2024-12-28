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
    string _modalitat;

public:

    DTOContingut();
    DTOContingut(string titol, string descripcio, string qualificacio, string tipus, string modalitat);

    //GETTERS
    string obteTitol();
    string obteDescripcio();
    string obteQualificacio();
    string obteTipus();
    string obteModalitat();
    
    //SETTERS
    void setTitol(string titol);
    void setDescripcio(string descripcio);
    void setQualificacio(string qualificacio);
    void setTipus(string tipus);
    void setModalitat(string modalitat);

    DTOContingut& operator=(const DTOContingut& obj);
};
#endif
