#ifndef CERCADORAVISUALITZACIOSERIE_HPP
#define CERCADORAVISUALITZACIOSERIE_HPP
#pragma once
#include "PassarelaVisualitzaSerie.h"
#include <string>
using namespace std;
using namespace sql;

class CercadoraVisualitzaSerie {
private:
    

public:
    CercadoraVisualitzaSerie();

    PassarelaVisualitzaSerie cercaVisualitzaSerie(string sobrenomU);
};
#endif