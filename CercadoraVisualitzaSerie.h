#ifndef CERCADORAVISUALITZACIOSERIE_HPP
#define CERCADORAVISUALITZACIOSERIE_HPP
#pragma once
#include "PassarelaVisualitzaSerie.h"
#include "connexioDB.h"
#include <string>
#include <vector>
using namespace std;
using namespace sql;

class CercadoraVisualitzaSerie {
private:
    

public:
    CercadoraVisualitzaSerie();

    vector<PassarelaVisualitzaSerie> cercaVisualitzaSerie(string sobrenomU);
};
#endif