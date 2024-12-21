#ifndef PASSARELAUSUARI_HPP
#define PASSARELAUSUARI_HPP
#pragma once
#include "connexioDB.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include "Data.h"
using namespace std;

class PassarelaUsuari {
private:
    static PassarelaUsuari* ins;

    string _sobrenom;
    string _nom;
    string _contrasenya;
    string _correuElectronic;
    Data _dataNaixament;
    string _modalitatSubscripcio;

public:
    PassarelaUsuari();

    PassarelaUsuari(string sobrenomU, string nomU, string correuElectronicU);
    PassarelaUsuari(string nomU, string sobrenomU, string contrasenyaU, string correuElectronicU, Data dataNaixementU, string modalitatU);

    //SETTERS
    string obteSobrenom();
    string obteNom();
    string obteContrasenya();
    string obteCorreuElectronic();
    Data obteDataNaixament();
    string obteModalitatSubscripcio();

    PassarelaUsuari& operator=(const PassarelaUsuari& obj);

    //GETTERS
    void setSobrenom(string sobrenom);
    void setNom(string nom);
    void setContrasenya(string contrasenya);
    void setCorreuElectronic(string correuElectornic);
    void setDataNaixament(Data dataNaixement);
    void setModalitatSubscripcio(string modalitatSubscripcio);

    void insereix();
    void modifica();
    void esborra();
};
#endif