#ifndef PASSARELAPEL_HPP
#define PASSARELAPEL_HPP
#pragma once

#include "connexioDB.h"
#include "utils.h"
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;
using namespace utils;

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

    //GETTERS
    string obteSobrenom() const;
    string obteTitolPelicula() const;
    string obteData() const;
    int obteNumVisualitzacions() const;

    //SETTERS
    void setSobrenom(string sobrenom);
    void setTitolPelicula(string titolP);
    void setData(string data);
    void setNumVisualitzacions(int nVis);

    // Métodos adicionales
    void insereix();
    void modifica();
    void esborra();

    ~PassarelaVisualitzaPel();
};

#endif
