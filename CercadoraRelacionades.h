#ifndef CERCADORARELACIONADES_HPP
#define CERCADORARELACIONADES_HPP
#pragma once
#include <string>
#include <vector>
using namespace std;
#include <iostream>
#include "connexioDB.h"

class CercadoraRelacionades {
private:

public:

    CercadoraRelacionades();

    vector<string> cercaRelacionades(string titolC);
};
#endif

