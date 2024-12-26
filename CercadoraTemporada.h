#ifndef CERCADORATEMPORADA_HPP
#define CERCADORATEMPORADA_HPP
#pragma once
#include <string>
#include "PassarelaTemporada.h"
#include "connexioDB.h"
#include <stdexcept>  // Para std::runtime_error 
using namespace std;


class CercadoraTemporada {
private:


public:

    CercadoraTemporada();

    //Obté la temporada en concret.
    PassarelaTemporada cercaTemporada(string titolS, int numTemporada);

    //Obté totes les temproades d' una sèrie.
    vector<PassarelaTemporada> cercaTemporades(string titolS);

};
#endif