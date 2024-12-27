#ifndef CERCADORACAPITOL_HPP
#define CERCADORACAPITOL_HPP
#pragma once
#include "PassarelaCapitol.h"
#include <vector>
#include <string>


class CercadoraCapitol {
private:

public:
    CercadoraCapitol();

    vector<PassarelaCapitol> cercaCapitolsTemporada(string titolS, int numTemporada);
};
#endif

