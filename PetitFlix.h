#ifndef PETITFLIX_HPP
#define PETITFLIX_HPP
#pragma once

#include "PassarelaUsuari.h"
#include "PassarelaVisualitzaSerie.h"

class PetitFlix {
private:
    static PetitFlix* _ins; 

    PetitFlix(); 

    static PassarelaUsuari* _usuari;

public:
    //Constructors
    static PetitFlix& getInstance();

    //Consultors
    PassarelaUsuari* obteUsuari();

    PassarelaVisualitzaSerie* obteSerie();

    //Modificadors
    static void iniciaSessio(PassarelaUsuari u); 
    void tancaSessio(); 
    void modificaUsuari(string nom, string contrasenya, string dataN, string correuE, string modalitatS);
    void modificaContrasenya(string contrasenya);

};

#endif 
