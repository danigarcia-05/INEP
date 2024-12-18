#pragma once
#ifndef CAPADEDOMINI_HPP
#define CAPADEDOMINI_HPP
#include <string>
#include "DTOUsuari.h"

class CapaDeDomini {
private:
    static CapaDeDomini* ins;

    CapaDeDomini();


public:
    CapaDeDomini* getins();

    registrarUsuari(string sobrenomU, string nomU, string correuU);
    
};

#endif