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
    string _subscripcio;

public:
    PassarelaContingut();

    PassarelaContingut(string titol, string descripcio, string qualificacio, string tipus, string subscripcio);

    //GETTERS
    string obteTitol() const;
    string obteDescripcio() const;
    string obteQualificacio() const;
    string obteTipus() const;
    string obteSubscripcio() const;

    PassarelaContingut& operator=(const PassarelaContingut& obj);

    //SETTERS
    void setTitol(string titol);
    void setDescripcio(string descripcio);
    void setQualificacio(string qualificacio);
    void setTipus(string tipus);
    void setSubscripcio(string subscripcio);

    void insereix();
    void modifica();
    void esborra();

    ~PassarelaContingut();
};
#endif