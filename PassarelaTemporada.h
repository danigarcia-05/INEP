#ifndef PASSARELATEMPORADA_HPP
#define PASSARELATEMPORADA_HPP
#pragma once
#include "connexioDB.h"
#include "utils.h"
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;
using namespace utils;

class PassarelaTemporada {
private:
    string _titolS;
    int _numTemporada;

public:
    PassarelaTemporada();

    PassarelaTemporada(string titolS, int numTemporada);

    //GETTERS
    string obteTitolSerie();
    int obteNumTemporada();
    
    PassarelaTemporada& operator=(const PassarelaTemporada& obj);

    //SETTERS
    void setTitol(string titol);
    void setNumTemporada(int numTemporada);

    void insereix();
    void esborra();
};
#endif