#ifndef CERCADORAUSUARI_HPP
#define CERCADORAUSUARI_HPP
#pragma once
#include<string>
#include "PassarelaUsuari.h"

class CercadoraUsuari {
private:
    

public:

    CercadoraUsuari();

    PassarelaUsuari cercaUsuari(string sobrenomU) const;

};
#endif