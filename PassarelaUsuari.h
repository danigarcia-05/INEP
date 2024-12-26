#ifndef PASSARELAUSUARI_HPP
#define PASSARELAUSUARI_HPP
#pragma once
#include "connexioDB.h"
#include "utils.h"
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;
using namespace utils;

class PassarelaUsuari {
private:
    static PassarelaUsuari* ins;

    string _sobrenom;
    string _nom;
    string _contrasenya;
    string _correuElectronic;
    string _dataNaixament;
    string _modalitatSubscripcio;

public:
    PassarelaUsuari();

    PassarelaUsuari(string sobrenomU, string nomU, string correuElectronicU);
    PassarelaUsuari(string nomU, string sobrenomU, string contrasenyaU, string correuElectronicU, string dataNaixementU, string modalitatU);

    //GETTERS
    string obteSobrenom();
    string obteNom();
    string obteContrasenya();
    string obteCorreuElectronic();
    string obteDataNaixament();
    string obteModalitatSubscripcio();

    PassarelaUsuari& operator=(const PassarelaUsuari& obj);

    //SETTERS
    void setSobrenom(string sobrenom);
    void setNom(string nom);
    void setContrasenya(string contrasenya);
    void setCorreuElectronic(string correuElectornic);
    void setDataNaixament(string dataNaixement);
    void setModalitatSubscripcio(string modalitatSubscripcio);

    void insereix();
    void modifica();
    void esborra();
};
#endif