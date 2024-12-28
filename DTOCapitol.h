#ifndef DTOCAPITOL_HPP
#define DTOCAPITOL_HPP
#pragma once
#include <string>
using namespace std;
#include "PassarelaCapitol.h"

class DTOCapitol {
private:
    string _titolSerie;
    int _numTemporada;
    int _numero;
    string _titol;
    string _dataEstrena;
    string _qualificacio;
    int _duracioC;
    string _modalitat;
public:

    DTOCapitol();
    DTOCapitol(string titolS, int numTemporada, int numero, string titol, string dataEstrena, string qualificacio, int duracioC, string modalitat);

    //GETTERS
    string obteTitolS();
    int obteNumTemp();
    int obteNumCap();
    string obteTitolC();
    string obteDataEstrena();
    string obteQualificacio();
    int obteDuracioC();
    string obteModalitat();
    
    //SETTERS
    void setTitolS(string titolS);
    void setNumTemp(int numTemp);
    void setNumCap(int NumCap);
    void setTitolC(string titolC);
    void setDataEstrena(string dataEstrena);
    void setQualificacio(string qualificacio);
    void setDuracioC(int duracioC);
    void setModalitat(string modalitat);

    DTOCapitol& operator=(const DTOCapitol& obj);
};
#endif
