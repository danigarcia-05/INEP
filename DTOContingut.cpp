#include "DTOContingut.h"

// Constructor por defecto
DTOContingut::DTOContingut() 
    : _titol(""), _descripcio(""), _qualificacio(""), _tipus(""), _modalitat("") {}

// Constructor con parámetros
DTOContingut::DTOContingut(string titol, string descripcio, string qualificacio, string tipus, string modalitat) 
    : _titol(titol), _descripcio(descripcio), _qualificacio(qualificacio), _tipus(tipus), _modalitat(modalitat) {}

// Getters
string DTOContingut::obteTitol() const{
    return _titol;
}

string DTOContingut::obteDescripcio() const{
    return _descripcio;
}

string DTOContingut::obteQualificacio() const{
    return _qualificacio;
}

string DTOContingut::obteTipus() const{
    return _tipus;
}

string DTOContingut::obteModalitat() const{
    return _modalitat;
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

void DTOContingut::setModalitat(string modalitat) {
    _modalitat = modalitat;
}


// Operador d'assignació
DTOContingut& DTOContingut::operator=(const DTOContingut& obj) {
    if (this != &obj) {
        _titol = obj._titol;
        _descripcio = obj._descripcio;
        _qualificacio = obj._qualificacio;
        _tipus = obj._tipus;
        _modalitat = obj._modalitat;
    }
    return *this;
}