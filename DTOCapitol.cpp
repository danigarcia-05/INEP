#include "DTOCapitol.h"

// Constructor por defecto
DTOCapitol::DTOCapitol() 
    : _titolSerie(""), _numTemporada(0), _numero(0), _titol(""), _dataEstrena(""), _qualificacio("") {}

// Constructor parametrizado
DTOCapitol::DTOCapitol(string titolS, int numTemporada, int numero, string titol, string dataEstrena, string qualificacio) 
    : _titolSerie(titolS), _numTemporada(numTemporada), _numero(numero), _titol(titol), _dataEstrena(dataEstrena), _qualificacio(qualificacio) {}

// GETTERS
string DTOCapitol::obteTitolS() {
    return _titolSerie;
}

int DTOCapitol::obteNumTemp() {
    return _numTemporada;
}

int DTOCapitol::obteNumCap() {
    return _numero;
}

string DTOCapitol::obteTitolC() {
    return _titol;
}

string DTOCapitol::obteDataEstrena() {
    return _dataEstrena;
}

string DTOCapitol::obteQualificacio() {
    return _qualificacio;
}

// SETTERS
void DTOCapitol::setTitolS(string titolS) {
    _titolSerie = titolS;
}

void DTOCapitol::setNumTemp(int numTemp) {
    _numTemporada = numTemp;
}

void DTOCapitol::setNumCap(int numCap) {
    _numero = numCap;
}

void DTOCapitol::setTitolC(string titolC) {
    _titol = titolC;
}

void DTOCapitol::setDataEstrena(string dataEstrena) {
    _dataEstrena = dataEstrena;
}

void DTOCapitol::setQualificacio(string qualificacio) {
    _qualificacio = qualificacio;
}

// Operador de asignación
DTOCapitol& DTOCapitol::operator=(const DTOCapitol& obj) {
    if (this != &obj) {
        _titolSerie = obj._titolSerie;
        _numTemporada = obj._numTemporada;
        _numero = obj._numero;
        _titol = obj._titol;
        _dataEstrena = obj._dataEstrena;
        _qualificacio = obj._qualificacio;
    }
    return *this;
}
