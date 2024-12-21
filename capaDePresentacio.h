#ifndef CAPADEPRESENTACIO_HPP
#define CAPADEPRESENTACIO_HPP
#pragma once
#include "PassarelaUsuari.h"
using namespace std;
#include <iostream>
#include <string>
#include "TxIniciSessio.h"
#include "TxTancaSessio.h"
#include "TxEsborraUsuari.h"
#include "TxRegistraUsuari.h"
#include "TxConsultaUsuari.h"
#include "TxInfoVisualitzacions.h"
#include "CtrlModificaUsuari.h"
#include "utils.h"
#include <stdexcept>
#include <utility>

class CapaDePresentacio {
private:
    static CapaDePresentacio* ins;

    CapaDePresentacio();
 
public:
    static CapaDePresentacio& getInstance();
   
    void processarIniciarSessio();
    void processarTancaSessio();

    void processarRegistreUsuari();
    void processarConsultaUsuari();
    void processarModificaUsuari();
    void processarModificaContrasenya();
    void processarEsborraUsuari();

    void processarVisualitzarPelicula();
    void processarVisualitzarCapitol();
    void processarConsultarVisualitzacions();

    void processarUltimesNovetats();
    void processarProperesEstrenes();
    void processarPeliculesMesVistes();

    
};
#endif

