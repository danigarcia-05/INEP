#ifndef CAPADEPRESENTACIO_HPP
#define CAPADEPRESENTACIO_HPP
#pragma once
using namespace std;
#include <iostream>
#include <string>
#include "CapaDeDomini.h"

class CapaDePresentacio {
private:
    static CapaDePresentacio* ins;
    static PassarelaUsuari* insUsuari;

    CapaDePresentacio();
 
public:
    CapaDePresentacio* getInstance();
    bool getInstanceUsuari() const;

    void processarIniciarSessio();

    void processarRegistreUsuari();
    void processarConsultaUsuari();
    void processarModificaUsuari();
    void processarBorrarUsuari();

    void processarGestioPelicules();
    void processarGestioSeries();
    void processarConsultesEdat();

    void processarUltimesNovetats();
    void processarProximesEstrenes();
};
#endif

