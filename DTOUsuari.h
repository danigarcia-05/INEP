#ifndef DTOUSUARI_HPP
#define DTOUSUARI_HPP
#pragma once
#include <string>
using namespace std;
#include "Data.h"

#include "PassarelaUsuari.h"
class DTOUsuari{
public:

    DTOUsuari();
    DTOUsuari(string nomU, string sobrenomU, string  correuElectronicU, Data dataNaixementU, string  modalitatU);
    
    //GETTERS
    string obteNom();
    string obteSobrenom();
    string obteCorreu();
    Data obteDataN();
    string obteModalitatS();

    //SETTERS
    void setNom(string nom);
    void setSobrenom(string sobrenom);
    void setCorreu(string correuElectronic);
    void setDataN(Data dataNaixement);
    void setModalitatS(string modalitat);

    DTOUsuari& operator=(const DTOUsuari& obj);

private:
    string _sobrenom;
    string _nom;
    string _correuElectronic;
    Data _dataNaixement;
    string _modalitat;
};
#endif