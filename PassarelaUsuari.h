#ifndef PASSARELAUSUARI_HPP
#define PASSARELAUSUARI_HPP
#pragma once
#include "connexioDB.h"
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;


class PassarelaUsuari {
private:
    static PassarelaUsuari* ins;

    string _sobrenom;
    string _nom;
    string _contrasenya;
    string _correuElectronic;
    Data _dataNaixament;
    subscripcio _modalitatSubscripcio;

public:
    PassarelaUsuari();

    PassarelaUsuari(string sobrenomU, string nomU, string correuElectronicU);
    PassarelaUsuar(string nomU, string sobrenomU, string contrasenyaU, string correuElectronicU, string dataNaixementU, subscripcio modalitatU);

    string obteSobrenom();
    string obteNom();
    string obteContrasenya();
    string obteCorreuElectronic();
    Data obteDataNaixament();
    string obteModalitatSubscripcio();

    void insereix();
    void modifica();
    void esborra();
};
#endif