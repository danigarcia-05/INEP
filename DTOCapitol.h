#ifndef DTOCAPITOL_HPP
#define DTOCAPITOL_HPP
#pragma once
#include <string>
using namespace std;
#include "PassarelaCapitol.h"

class DTOCapitol {
public:

    DTOCapitol();
    DTOCapitol(string titolC, string dataEstrenaC, string visualitzatC);

    //GETTERS
    string obteTitol();
    string obteDataEstrena();
    string obteDataVisualitzat();
    
    //SETTERS
    void setTitol(string titol);
    void setDataEstrena(string dataEstrena);
    void setDataVisualitzat(string dataVisualitzat);

    DTOCapitol& operator=(const DTOCapitol& obj);

private:
    string _titol;
    string _dataEstrena;
    string _dataVisualitzat;
};
#endif
