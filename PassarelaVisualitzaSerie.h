#ifndef PASSARELAPEL_HPP
#define PASSARELAPEL_HPP
#pragma once

#include "connexioDB.h"
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;

class PassarelaVisualitzaSerie {
private:
    string _sobrenom;
    string _titolSerie;
    int _numVisualitzacions;
    int _numTemporada;
    int _numCapitol;
    Data _data;

public:
    
    PassarelaVisualitzaSerie(); 
    PassarelaVisualitzaSerie(string sobrenomU, string titolSerieU, int numVisualitzacionsU, int numTemporadaU, int numCapitolU, Data dataU);

    
    string obteSobrenom() const;
    void setSobrenom(const string& sobrenomU);

    string obteTitolSerie() const;
    void setTitolSerie(const string& titolSerieU);

    int obteNumVisualitzacions() const;
    void setNumVisualitzacions(int numVisualitzacionsU);

    int obteNumTemporada() const;
    void setNumTemporada(int numTemporadaU);

    int obteNumCapitol() const;
    void setNumCapitol(int numCapitolU);

    Data obteData() const;
    void setData(const Data& dataU);

    void insereix();
    void modifica();
    void esborra();
};

#endif
