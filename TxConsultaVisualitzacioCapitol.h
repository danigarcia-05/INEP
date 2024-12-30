#ifndef TXCONSULTAVISUALITZACIOCAPITOL_HPP
#define TXCONSULTAVISUALITZACIOCAPITOL_HPP
#pragma once
#include "PassarelaVisualitzaCapitol.h"
#include "PassarelaCapitol.h"
#include "CercadoraVisualitzaCapitol.h"
#include "CercadoraCapitol.h"
#include "DTOVisualitzacioCapitol.h"
#include "DTOCapitol.h"
#include "PetitFlix.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>  
#include <vector>  

class TxConsultaVisualitzacioCapitol {
private:
    PassarelaVisualitzaCapitol _capitolVisualitzat;
    DTOVisualitzacioCapitol _resultat;

    vector<PassarelaVisualitzaCapitol> _cjVisualitzacioCapitol;
    vector<DTOVisualitzacioCapitol> _capitolsVisualitzats;

public:
    TxConsultaVisualitzacioCapitol();
    void executar(string sobrenomU, string titolSerie, int numTemporada, int numero);
    void executarCV(string sobrenomU);
    PassarelaVisualitzaCapitol obteVisualitzacioCapitol();
    DTOVisualitzacioCapitol obteResultat();
    vector<DTOVisualitzacioCapitol> obteCapitolsVisualitzats();
    vector<PassarelaVisualitzaCapitol> obteConjuntVisualitzacionsCapitols();
    ~TxConsultaVisualitzacioCapitol();
};

#endif
