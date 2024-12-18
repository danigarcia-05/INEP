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

    static CapaDeDomini* getInstance() {
        if (ins == nullptr) {
            ins = new CapaDeDomini();  // Crear la instancia si aún no existe
        }
        return ins;
    }

    CapaDeDomini* getins();

    void iniciarSessio(string sobrenomU, string contrasenyaU);

    void registrarUsuari(string sobrenomU, string nomU, string correuU);
    
    
};

#endif