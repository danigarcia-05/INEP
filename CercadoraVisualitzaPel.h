#ifndef CERCADORAVISUALITZACIOPEL_HPP
#define CERCADORAVISUALITZACIOPEL_HPP
#pragma once
#include "PassarelaVisualitzaPel.h"
#include <vector>

class CercadoraVisualitzaPel {
private:
    
public:

    CercadoraVisualitzaPel();

    vector<PassarelaVisualitzaPel> cercaVisualitzaPel(string sobrenomU);

    PassarelaVisualitzaPel cercaVisualitzaPelEspecifica(string sobrenomU, string titolP);

};
#endif