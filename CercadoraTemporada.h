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

    //Obt� la temporada en concret.
    PassarelaTemporada cercaTemporada(string titolS, int numTemporada);

    //Obt� totes les temproades d' una s�rie.
    vector<PassarelaTemporada> cercaTemporades(string titolS);

};
#endif