#include "DTOContingut.h"

// Constructor por defecto
DTOContingut::DTOContingut() 
    : _titol(""), _descripcio(""), _qualificacio(""), _tipus("") {}

// Constructor con parámetros
DTOContingut::DTOContingut(string titol, string descripcio, string qualificacio, string tipus) 
    : _titol(titol), _descripcio(descripcio), _qualificacio(qualificacio), _tipus(tipus) {}

// Getters
string DTOContingut::obteTitol() {
    return _titol;
}

string DTOContingut::obteDescripcio() {
    return _descripcio;
}

string DTOContingut::obteQualificacio() {
    return _qualificacio;
}

string DTOContingut::obteTipus() {
    return _tipus;
}

// Setters
void DTOContingut::setTitol(string titol) {
    _titol = titol;
}

void DTOContingut::setDescripcio(string descripcio) {
    _descripcio = descripcio;
}

void DTOContingut::setQualificacio(string qualificacio) {
    _qualificacio = qualificacio;
}

void DTOContingut::setTipus(string tipus) {
    _tipus = tipus;
}

// Operador d'assignació
DTOContingut& DTOContingut::operator=(const DTOContingut& obj) {
    if (this != &obj) {
        _titol = obj._titol;
        _descripcio = obj._descripcio;
        _qualificacio = obj._qualificacio;
        _tipus = obj._tipus;
    }
    return *this;
}