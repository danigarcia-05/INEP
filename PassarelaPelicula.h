#ifndef PASSARELAPELICULA_HPP
#define PASSARELAPELICULA_HPP
#pragma once
#include "connexioDB.h"
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;

class PassarelaPelicula {
private:
    static PassarelaPelicula* ins;

    string _titol;
    string _descripcio;
    string _qualificacio;
    string _dataEstrena;
    string _tipus;
    int _duracio;

public:
    PassarelaPelicula();

    PassarelaPelicula(string titol, string descripcio, string qualificacio, string dataEstrena, string tipus, int duracio);

    //GETTERS
    string obteTitol();
    string obteDescripcio();
    string obteQualificacio();
    string obteDataEstrena();
    string obteTipus();
    int obteDuracio();

    PassarelaPelicula& operator=(const PassarelaPelicula& obj);

    //SETTERS
    void setTitol(string titol);
    void setDescripcio(string descripcio);
    void setQualificacio(string qualificacio);
    void setDataEstrena(string dataEstrena);
    void setTipus(string tipus);
    void setDuracio(int duracio);

    void insereix();
    void modifica();
    void esborra();
};
#endif