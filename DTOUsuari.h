#ifndef DTOUSUARI_HPP
#define DTOUSUARI_HPP
#pragma once
#include <string>
using namespace std;
#include "PassarelaUsuari.h"

class DTOUsuari{
public:

    DTOUsuari();
    DTOUsuari(string nomU, string sobrenomU, string  correuElectronicU, string dataNaixementU, string modalitatU);
    
    //GETTERS
    string obteNom() const;
    string obteSobrenom() const;
    string obteCorreu() const;
    string obteDataN() const;
    string obteModalitatS() const;

    //SETTERS
    void setNom(string nom);
    void setSobrenom(string sobrenom);
    void setCorreu(string correuElectronic);
    void setDataN(string dataNaixement);
    void setModalitatS(string modalitat);

    DTOUsuari& operator=(const DTOUsuari& obj);

private:
    string _sobrenom;
    string _nom;
    string _correuElectronic;
    string _dataNaixement;
    string _modalitat;
};
#endif