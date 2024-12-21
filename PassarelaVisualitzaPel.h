#ifndef PASSARELAPEL_HPP
#define PASSARELAPEL_HPP
#pragma once

#include "connexioDB.h"
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;
#include "Data.h"

class PassarelaVisualitzaPel {
private:
    string _sobrenom;
    string _titolPelicula;
    Data _data;
    int _numVisualitzacions;

public:
    // Constructores
    PassarelaVisualitzaPel();  // Constructor por defecto
    PassarelaVisualitzaPel(string sobrenomU, string titolPeliculaU, Data dataU, int numVisualitzacionsU);

    // Getters y Setters
    string obteSobrenom() const;
    void setSobrenom(const string& sobrenomU);

    string obteTitolPelicula() const;
    void setTitolPelicula(const string& titolPeliculaU);

    Data obteData() const;
    void setData(const Data& dataU);

    int obteNumVisualitzacions() const;
    void setNumVisualitzacions(int numVisualitzacionsU);

    // Métodos adicionales
    void insereix();
    void modifica();
    void esborra();
};

#endif
