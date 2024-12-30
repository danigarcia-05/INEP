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

     CercadoraVisualitzaCapitol();

public:

   static CercadoraVisualitzaCapitol& getInstance();

    PassarelaVisualitzaCapitol cercaVisualitzaCapitol(string sobrenomU, string nomS, int numTemporada, int numCapitol);

    vector<PassarelaVisualitzaCapitol> cercaVisualitzaCapitolsUsuari(string sobrenomU);

    ~CercadoraVisualitzaCapitol();
};
#endif