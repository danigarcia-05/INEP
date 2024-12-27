#ifndef PASSARELAPELICULA_HPP
#define PASSARELAPELICULA_HPP
#pragma once
#include "connexioDB.h"
#include "utils.h"
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;

class PassarelaPelicula {
private:
    string _titol;
    string _dataEstrena;
    int _duracio;
    int _visualitzacionsGlobals;

public:
    PassarelaPelicula();

    PassarelaPelicula(string titol, string dataEstrena, int duracio, int visualitzacionsGlobals);

    //GETTERS
    string obteTitol();
    string obteDataEstrena();
    int obteDuracio();
    int obteVisualitzacionsGlobals();

    PassarelaPelicula& operator=(const PassarelaPelicula& obj);

    //SETTERS
    void setTitol(string titol);
    void setDataEstrena(string dataEstrena);
    void setDuracio(int duracio);
    void setVisualitzacionsGlobals(int visualitzacionsGlobals);

    void insereix();
    void modifica();
    void esborra();
};
#endif