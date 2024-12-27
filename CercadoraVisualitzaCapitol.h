#ifndef CERCADORAVISUALITZACAPITOL_HPP
#define CERCADORAVISUALITZACAPITOL_HPP
#pragma once
#include "PassarelaVisualitzaCapitol.h"
#include "connexioDB.h"
#include <string>
#include <vector>
using namespace std;
using namespace sql;

class CercadoraVisualitzaCapitol {
private:
    

public:

    CercadoraVisualitzaCapitol();

    PassarelaVisualitzaCapitol cercaVisualitzaCapitol(string sobrenomU, string nomS, int numTemporada, int numCapitol);

    vector<PassarelaVisualitzaCapitol> cercaVisualitzaCapitolsUsuari(string sobrenomU);
};
#endif