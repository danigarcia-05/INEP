#ifndef PASSARELACONTINGUT_HPP
#define PASSARELACONTINGUT_HPP
#pragma once
#include "connexioDB.h"
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;

class PassarelaContingut {
private:
    string _titol;
    string _descripcio;
    string _qualificacio;
    string _tipus;

public:
    PassarelaContingut();

    PassarelaContingut(string titol, string descripcio, string qualificacio, string tipus);

    //GETTERS
    string obteTitol();
    string obteDescripcio();
    string obteQualificacio();
    string obteTipus();

    PassarelaContingut& operator=(const PassarelaContingut& obj);

    //SETTERS
    void setTitol(string titol);
    void setDescripcio(string descripcio);
    void setQualificacio(string qualificacio);
    void setTipus(string tipus);

    void insereix();
    void modifica();
    void esborra();
};
#endif