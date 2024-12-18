#ifndef TXINICISESSIO_HPP
#define TXINICISESSIO_HPP
#pragma once
#include <string>

class TxIniciSessio {
private:
    string SobrenomU;
    string ContrasenyaU;

public:
    void crear(string sU, string cU);

    void executar();
};

#endif