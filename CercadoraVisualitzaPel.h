#ifndef CERCADORAVISUALITZACIOPEL_HPP
#define CERCADORAVISUALITZACIOPEL_HPP
#pragma once
#include "PassarelaVisualitzaPel.h"
#include <vector>

class CercadoraVisualitzaPel {
private:

    CercadoraVisualitzaPel();

public:

    static CercadoraVisualitzaPel& getInstance();

    vector<PassarelaVisualitzaPel> cercaVisualitzaPel(string sobrenomU);

    PassarelaVisualitzaPel cercaVisualitzaPelEspecifica(string sobrenomU, string titolP);

    ~CercadoraVisualitzaPel();

};
#endif