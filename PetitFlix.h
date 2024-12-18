#ifndef PETITFLIX_HPP
#define PETITFLIX_HPP
#pragma once

#include "Passarel·laUsuari.h"

class PetitFlix {
private:
    static PetitFlix* ins; 

    PetitFlix(); 

    Passarel·laUsuari* passarel·laUsuari; // Puntero para 0..1 multiplicidad

public:
    static PetitFlix* getins();

    Passarel·laUsuari* obteUsuari();
    void iniciaSessio(); 
    void tancaSessio();                 
};

#endif 
