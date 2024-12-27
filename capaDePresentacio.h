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
#include "CtrlVisualitzaPelicula.h"
#include "CtrlVisualitzaCapitol.h"
#include "DTOVisualitzacioCapitol.h"
#include "TxConsultaVisualitzacioCapitol.h"
#include "utils.h"
using namespace utils;
#include <stdexcept>
#include <utility>
#include "PetitFlix.h"
#include "connexioDB.h"
#include <locale>
#include <vector>
#include "DTOUsuari.h"
#include "DTOPelicula.h"

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

