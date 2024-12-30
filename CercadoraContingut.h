#ifndef CERCADORACONTINGUT_HPP
#define CERCADORACONTINGUT_HPP
#pragma once
#include "PassarelaContingut.h"
#include <vector>

class CercadoraContingut {
private:
    CercadoraContingut();
    
public:
    static CercadoraContingut& getInstance();

    ~CercadoraContingut();

    PassarelaContingut cercaContingut(string titolC);
    vector<PassarelaContingut> cercaContingutRelacionat(string titolC);
};
#endif

