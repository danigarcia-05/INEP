#pragma once
#ifndef CAPADEDOMINI_HPP
#define TXINFOVISUALITZACIONS_HPP

class CapaDeDomini {
private:
    static CapaDeDomini* ins;

    CapaDeDomini();


public:
    CapaDeDomini* getins();

    registrarUsuari(string sobrenomU, string nomU, string correuU);
    
};

#endif