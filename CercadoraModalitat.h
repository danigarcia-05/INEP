#ifndef CERCADORAMODALITAT_HPP
#define CERCADORAMODALITAT_HPP
#pragma once
#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;
#include "connexioDB.h"


class CercadoraModalitat {
private:
    CercadoraModalitat();
    
public:
    static CercadoraModalitat& getInstance();

    ~CercadoraModalitat();

    void existeix(string mod);
};
#endif
