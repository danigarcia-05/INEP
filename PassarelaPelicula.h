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

public:
    PassarelaPelicula();

    PassarelaPelicula(string titol, string dataEstrena, int duracio);

    //GETTERS
    string obteTitol();
    string obteDataEstrena();
    int obteDuracio();

    PassarelaPelicula& operator=(const PassarelaPelicula& obj);

    //SETTERS
    void setTitol(string titol);
    void setDataEstrena(string dataEstrena);
    void setDuracio(int duracio);

    void insereix();
    void modifica();
    void esborra();
};
#endif