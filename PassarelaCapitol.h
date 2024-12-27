#ifndef PASSARELACAPITOL_HPP
#define PASSARELACAPITOL_HPP
#pragma once
#include "connexioDB.h"
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;

class PassarelaCapitol {
private:
    string _titolSerie;
    int _numTemporada;
    int _numero;
    string _titol;
    string _dataEstrena;
    string _qualificacio;

public:
    PassarelaCapitol();

    PassarelaCapitol(string titolSerie, int numT, int numC, string titol, string dataEstrena, string qualificacio);

    // GETTERS
    string obteTitolSerie(); 

    int obteNumTemporada(); 

    int obteNumero(); 

    string obteTitol();

    string obteSobrenom(); 

    string obteDataEstrena(); 

    string obteQualificacio();

    // SETTERS
    void setTitolSerie(string titolSerie); 

    void setNumTemporada(int numTemporada);

    void setNumero(int numero);

    void setTitol(string titol);

    void setDataEstrena(string dataEstrena); 

    void setQualificacio(string qualificacio);

    PassarelaCapitol& operator=(const PassarelaCapitol& obj);


    void insereix();
    void modifica();
    void esborra();
};
#endif