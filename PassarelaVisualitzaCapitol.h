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
    string obteSobrenom();
    string obteTitolSerie();
    int obteNumVisualitzacions();
    int numTemporada();
    int numCapitol();
    string obteData();
    

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
};

#endif
