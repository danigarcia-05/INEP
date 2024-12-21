#ifndef PASSARELASERIE_HPP
#define PASSARELASERIE_HPP
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
    string _data;

public:
    
    PassarelaVisualitzaSerie(); 
    PassarelaVisualitzaSerie(string sobrenomU, string titolSerieU, int numVisualitzacionsU, int numTemporadaU, int numCapitolU, string dataU);

    
    string obteSobrenom() const;
    void setSobrenom(const string sobrenomU);

    string obteTitolSerie() const;
    void setTitolSerie(const string titolSerieU);

    int obteNumVisualitzacions() const;
    void setNumVisualitzacions(int numVisualitzacionsU);

    int obteNumTemporada() const;
    void setNumTemporada(int numTemporadaU);

    int obteNumCapitol() const;
    void setNumCapitol(int numCapitolU);

    Data obteData() const;
    void setData(const string dataU);

    void insereix();
    void modifica();
    void esborra();
};

#endif
