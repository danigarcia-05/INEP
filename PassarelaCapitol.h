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
    int _duracio;
    string _modalitat;

public:
    PassarelaCapitol();

    PassarelaCapitol(string titolSerie, int numT, int numC, string titol, string dataEstrena, string qualificacio, int duracio, string modalitat);

    // GETTERS
    string obteTitolSerie() const; 

    int obteNumTemporada() const; 

    int obteNumero() const; 

    string obteTitol() const;

    string obteDataEstrena() const; 

    string obteQualificacio() const;

    int obteDuracio() const;

    string obteModalitat() const;

    // SETTERS
    void setTitolSerie(string titolSerie); 

    void setNumTemporada(int numTemporada);

    void setNumero(int numero);

    void setTitol(string titol);

    void setDataEstrena(string dataEstrena); 

    void setQualificacio(string qualificacio);

    void setDuracio(int duracio);

    void setModalitat(string modalitat);

    PassarelaCapitol& operator=(const PassarelaCapitol& obj);


    void insereix();
    void modifica();
    void esborra();
};
#endif