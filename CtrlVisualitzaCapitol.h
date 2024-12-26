#ifndef CTRLVISUALITZACAPITOL_HPP
#define CTRLVISUALITZACAPITOL_HPP
#pragma once
#include "DTOCapitol.h"
#include "PassarelaCapitol.h"
#include "TxConsultaPelicula.h"
#include "PetitFlix.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

class CtrlVisualitzaCapitol {
private:

    PassarelaCapitol _capitol;
    vector<DTOCapitol> _capitols;
    PassarelaVisualitzaCapitol _capitolUsuari;

public:
    CtrlVisualitzaCapitol();

    int obteNumTemporades(string nomS);

    vector<DTOCapitol> obteCapitols(int numTemporada);

    vector<DTOCapitol> obteResultatCapitols();

    string consultaSerieUsuari(string titolS, int numTemporada, int numCapitol);

    void visualitzaCapitol(string sobrenomU, string titolS, int numTemporada, int numCapitol);
};
#endif
