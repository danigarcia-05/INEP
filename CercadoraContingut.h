#ifndef CERCADORACONTINGUT_HPP
#define CERCADORACONTINGUT_HPP
#pragma once
#include "PassarelaContingut.h"
#include <vector>

class CercadoraContingut {
private:

public:
    CercadoraContingut();

    PassarelaContingut cercaContingut(string titolC);
    //vector<PassarelaContingut> cercaContingutRelacionat(string titolC);
};
#endif

