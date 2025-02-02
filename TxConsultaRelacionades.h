#ifndef TXPELICULESRELACIONADES_HPP
#define TXPELICULESRELACIONADES_HPP
#pragma once
#include "DTOPelicula.h"
#include "CercadoraRelacionades.h"
#include "PetitFlix.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>  
#include <vector>  

class TxConsultaRelacionades {
private:
    vector<string> _relacionades;

public:
    TxConsultaRelacionades();
    void executar(string titolC);
    vector<string> obteRelacionades();
    ~TxConsultaRelacionades();
};

#endif


