#ifndef TXINICISESSIO_HPP
#define TXINICISESSIO_HPP
#pragma once
#include <string>

class TxIniciSessio {
private:
    string _sobrenomU;
    string _contrasenyaU;

public:
    //Constructors
    TxIniciSessio(string sU, string cU);

    //Destructors
    ~TxIniciSessio();

    //Modificadors
    void executar();
};

#endif