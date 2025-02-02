#ifndef PASSARELAVISUALITZACAPITOL_HPP
#define PASSARELAVISUALITZACAPITOL_HPP
#pragma once

#include "connexioDB.h"
#include "utils.h"
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;
using namespace utils;

class PassarelaVisualitzaCapitol {
private:
    string _sobrenom;
    string _titolSerie;
    int _numVisualitzacions;
    int _numTemporada;
    int _numCapitol;
    string _data;

public:
    
    PassarelaVisualitzaCapitol(); 
    PassarelaVisualitzaCapitol(string sobrenomU, string titolSerieU, int numVisualitzacionsU, int numTemporadaU, int numCapitolU, string dataU);

    //GETTERS
    string obteSobrenom() const;
    string obteTitolSerie() const;
    int obteNumVisualitzacions() const;
    int obteNumTemporada() const;
    int obteNumCapitol() const;
    string obteData() const;
    

    //SETTERS
    void setSobrenom(string sobrenom);
    void setTitolSerie(string titolS);
    void setNumVisualitzacions(int nVis);
    void setNumTemporada(int temp);
    void setNumCapitol(int cap);
    void setData(string data);
    
    void insereix();
    void modifica();
    void esborra();

    ~PassarelaVisualitzaCapitol();
};

#endif
