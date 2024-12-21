#ifndef CERCADORAUSUARI_HPP
#define CERCADORAUSUARI_HPP
#pragma once
#include<string>
#include "PassarelaUsuari.h"
#include "connexioDB.h"
#include <stdexcept>  // Para std::runtime_error 
using namespace std;


class CercadoraUsuari {
private:
    

public:

    CercadoraUsuari();

    PassarelaUsuari cercaUsuari(string sobrenomU) const;

};
#endif