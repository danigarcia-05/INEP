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
    string _modalitatSubscripcio;

public:
    PassarelaUsuari();

    PassarelaUsuari(string sobrenomU, string nomU, string correuElectronicU);
    PassarelaUsuar(string nomU, string sobrenomU, string contrasenyaU, string correuElectronicU, string dataNaixementU, string modalitatU);

    string obteSobrenom();
    string obteNom();
    string obteContrasenya();
    string obteCorreuElectronic();
    Data obteDataNaixament();
    string obteModalitatSubscripcio();

    void entraSobrenom(string sobrenom);
    void entraNom(string nom);
    void entraContrasenya(string contrasenya);
    void entraCorreuElectronic(string correuElectornic);
    void entraDataNaixament(data dataNaixement);
    void entraModalitatSubscripcio(dubscripcio modalitatSubscripcio);


    void insereix();
    void modifica();
    void esborra();
};
#endif