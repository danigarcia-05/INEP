#ifndef CERCADORACAPITOL_HPP
#define CERCADORACAPITOL_HPP
#pragma once
#include "PassarelaCapitol.h"
#include <vector>
#include <string>
#include <locale>


class CercadoraCapitol {
private:

public:
    CercadoraCapitol();

    vector<PassarelaCapitol> cercaCapitolsTemporada(string titolS, int numTemporada);
    vector<PassarelaCapitol> cercaNovesEstrenes(string mod);
    vector<PassarelaCapitol> cercaProperesEstrenes(string mod);
};
#endif

