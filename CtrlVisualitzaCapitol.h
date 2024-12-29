#ifndef CTRLVISUALITZACAPITOL_HPP
#define CTRLVISUALITZACAPITOL_HPP
#pragma once
#include "DTOCapitol.h"
#include "PassarelaCapitol.h"
#include "TxConsultaPelicula.h"
#include "CercadoraTemporada.h"
#include "TxConsultaCapitols.h"
#include "TxConsultaVisualitzacioCapitol.h"
#include "PetitFlix.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

class CtrlVisualitzaCapitol {
private:
    PassarelaVisualitzaCapitol _capitolUsuari;
    vector<PassarelaTemporada> _temporades;
    vector<PassarelaCapitol> _capitols;

public:
    CtrlVisualitzaCapitol();

    int obteNumTemporades(string nomS);

    vector<DTOCapitol> obteCapitolsTemp(string nomS, int numTemporada);

    string consultaSerieUsuari(string titolS, int numTemporada, int numCapitol);

    void visualitzaCapitol(string sobrenomU, string titolS, int numTemporada, int numCapitol);


};
#endif
