#ifndef CAPADEPRESENTACIO_HPP
#define CAPADEPRESENTACIO_HPP
#pragma once
using namespace std;
#include <iostream>
#include <string>


class CapaDePresentacio {
private:
    static CapaDePresentacio* ins;

    CapaDePresentacio();

    struct Usuari {
        string sobrenom;
        string nom;
        string correu;
    };  

public:
    CapaDePresentacio* getInstance();

    void processarIniciarSessio();

    void processarRegistreUsuari();
    void processarConsultarUsuari();
    void processarModificarUsuari();
    void processarBorrarUsuari();

    void processarGestioPelicules();
    void processarGestioSeries();
    void processarConsultesEdat();

    void processarUltimesNovetats();
    void processarProximesEstrenes();
};
#endif

