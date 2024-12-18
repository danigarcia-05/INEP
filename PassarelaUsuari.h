#ifndef PASSARELAUSUARI_HPP
#define PASSARELAUSUARI_HPP
#pragma once
#include<string>

class PassarelaUsuari {
private:
    static PassarelaUsuari* ins;

    string sobrenom;
    string nom;
    string contrasenya;
    string correuElectronic;
    Data dataNaixament;
    string modalitatSubscripcio;

public:
    PassarelaUsuari();

    PassarelaUsuari(string sobrenomU, string nomU, string correuElectronicU);

    void insereix();
};
#endif