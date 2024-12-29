#ifndef DTOVISUALITZACIOPELICULA_HPP
#define DTOVISUALITZACIOPELICULA_HPP
#pragma once
#include <string>
using namespace std;
#include "PassarelaPelicula.h"

class DTOVisualitzacioPelicula {
public:

    DTOVisualitzacioPelicula();
    DTOVisualitzacioPelicula(string titolP, string sobrenomU, string dataVP, int visualitzacions);

    //GETTERS
    string obteTitol() const;
    string obteSobrenom() const;
    string obteDataVP() const;
    int obteVisualitzacions() const;

    //SETTERS
    void setTitol(string titol);
    void setSobrenom(string sobrenom);
    void setDataVP(string data);
    void setVisualitzacions(int visualitzacions);

    DTOVisualitzacioPelicula& operator=(const DTOVisualitzacioPelicula& obj);

private:
    string _titol;
    string _sobrenom;
    string _dataVP;
    int _visualitzacions;
};
#endif
