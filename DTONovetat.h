#ifndef DTONOVETAT_HPP
#define DTONOVETAT_HPP
#pragma once
#include <string>
using namespace std;

class DTONovetat {
private:

    string _data;
    string _tipus;
    string _titol;
    string _qualificacio;
    int _detalls; // Ex: "120 min." o "Temporada 2"

public:
    DTONovetat();
    DTONovetat(string data, string tipus, string titol, string qualificacio, int detalls);

    string obteData() const;
    string obteTipus() const;
    string ObteTitol() const;
    string obteQualificacio() const;
    int obteDetalls() const;

    void setData(string data);
    void setTiups(string tipus);
    void setTitol(string qualificacio);
    void setQualificacio(string qualificacio);
    void setDetalls(int detalls);
    
};
#endif

