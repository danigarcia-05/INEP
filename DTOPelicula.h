#ifndef DTOPELICULA_HPP
#define DTOPELICULA_HPP
#pragma once
#include <string>
using namespace std;
#include "PassarelaVisualitzaPel.h"

class DTOPelicula {
public:

    DTOPelicula();
    DTOPelicula(string sobrenomU, string titolPelU, string  dataU, int numVisU);

    //GETTERS
    string obteSobrenom();
    string obteTitolP();
    string obteData();
    int obteNumVis();

    //SETTERS
    void setSobrenom(string sobrenom);
    void setTitolP(string titolP);
    void setData(string data);
    void setNumVis(int numVis);

    DTOPelicula& operator=(const DTOPelicula& obj);

private:
    string _sobrenom;
    string _titolPelicula;
    string _data;
    int _numVisualutzacions;
};
#endif
