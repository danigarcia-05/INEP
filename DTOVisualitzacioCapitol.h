#ifndef DTOVISUALITZACIOCAPITOL_HPP
#define DTOVISUALITZACIOCAPITOL_HPP
#pragma once
#include <string>
using namespace std;
#include "PassarelaCapitol.h"


class DTOVisualitzacioCapitol {
private:
    string _sobrenom;
    string _titolSerie;
    int _numTemporada;
    int _numCapitol;
    string _data;
    int _numVisualitzacions;

public:
    DTOVisualitzacioCapitol();
    DTOVisualitzacioCapitol(string sobrenom, string titolS, int numTemporada, int numCapitol, string data, int numVisualitzacions);

    // GETTERS
    string obteSobrenom();
    string obteTitolSerie();
    int obteNumTemporada();
    int obteNumCapitol();
    string obteData();
    int obteNumVisualitzacions();

    // SETTERS
    void setSobrenom(string sobrenom);
    void setTitolSerie(string titolS);
    void setNumTemporada(int numTemporada);
    void setNumCapitol(int numCapitol);
    void setData(string data);
    void setNumVisualitzacions(int numVisualitzacions);

    // Operador de asignación
    DTOVisualitzacioCapitol& operator=(const DTOVisualitzacioCapitol& obj);
};
#endif
