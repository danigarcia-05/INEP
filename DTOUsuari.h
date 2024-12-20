#ifndef DTOUSUARI_HPP
#define DTOUSUARI_HPP
#pragma once
#include <string>
using namespace std;

#include "PassarelaUsuari.h"
class DTOUsuari{
public:
    DTOUsuari();
    DTOUsuari(string nomU, string sobrenomU, string  correuElectronicU, ???  dataNaixementU, string  modalitatU);
    
    string obteNom();
    string obteSobrenom();
    string obteCorreu();
    string obteDataN();
    string obteModalitatS();

    DTOUsuari& operator=(const DTOUsuari& obj);
private:
    string _sobrenom;
    string _nom;
    string _correuElectronic;
    ??? _dataNaixement;
    string _modalitat;
};
#endif