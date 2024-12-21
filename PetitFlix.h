#ifndef PETITFLIX_HPP
#define PETITFLIX_HPP
#pragma once

#include "PassarelaUsuari.h"

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

    //Modificadors
    static void iniciaSessio(PassarelaUsuari u); 
    void tancaSessio(); 
          
};

#endif 
