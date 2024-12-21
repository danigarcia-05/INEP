#ifndef PASSARELAPEL_HPP
#define PASSARELAPEL_HPP
#pragma once

#include "connexioDB.h"
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;

class PassarelaVisualitzaPel {
private:
    string _sobrenom;
    string _titolPelicula;
    string _data;
    int _numVisualitzacions;

public:
    // Constructores
    PassarelaVisualitzaPel();  // Constructor por defecto
    PassarelaVisualitzaPel(string sobrenomU, string titolPeliculaU, string dataU, int numVisualitzacionsU);

    // Getters y Setters
    string obteSobrenom() const;
    void setSobrenom(const string& sobrenomU);

    string obteTitolPelicula() const;
    void setTitolPelicula(const string& titolPeliculaU);

    string obteData() const;
    void setData(const string& dataU);

    int obteNumVisualitzacions() const;
    void setNumVisualitzacions(int numVisualitzacionsU);

    // Métodos adicionales
    void insereix();
    void modifica();
    void esborra();
};

#endif
