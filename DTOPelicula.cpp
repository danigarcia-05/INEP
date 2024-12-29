#include "DTOPelicula.h"

// Constructor por defecto
DTOPelicula::DTOPelicula() 
    : _titol(""), _descripcio(""), _qualificacio(""), _data(""), _duracio(0), _tipus(""), _visGlobals(0), _subscripcio("") {}

// Constructor con parámetros
DTOPelicula::DTOPelicula(string titolP, string descripcioP, string qualificacioP, string dataP, int duracioP, string tipusP, int visGlobals, string subscripcio) 
    : _titol(titolP), _descripcio(descripcioP), _qualificacio(qualificacioP), _data(dataP), _duracio(duracioP), _tipus(tipusP), _visGlobals(visGlobals), _subscripcio(subscripcio) {}

// Getters
string DTOPelicula::obteTitol() const{
    return _titol;
}

string DTOPelicula::obteDescripcio() const{
    return _descripcio;
}

string DTOPelicula::obteQualificacio() const{
    return _qualificacio;
}

string DTOPelicula::obteDataP() const{
    return _data;
}

int DTOPelicula::obteDuracio() const{
    return _duracio;
}

string DTOPelicula::obteTipus() const{
    return _tipus;
}

int DTOPelicula::obteVisualitzacionsGlobals() const{
    return _visGlobals;
}

string DTOPelicula::obteSubscripcio() const{
    return _subscripcio;
}

// Setters
void DTOPelicula::setTitol(string titol) {
    _titol = titol;
}

void DTOPelicula::setDescripcio(string descripcio) {
    _descripcio = descripcio;
}

void DTOPelicula::setQualificacio(string qualificacio) {
    _qualificacio = qualificacio;
}

void DTOPelicula::setDataP(string data) {
    _data = data;
}

void DTOPelicula::setDuracio(int duracio) {
    _duracio = duracio;
}

void DTOPelicula::setTipus(string tipus) {
    _tipus = tipus;
}

void DTOPelicula::setVisualitzacionsGlobals(int visGlobals) {
    _visGlobals = visGlobals;
}

void DTOPelicula::setSubscripcio(string subscripcio) {
    _subscripcio = subscripcio;
}

// Operador de asignación
DTOPelicula& DTOPelicula::operator=(const DTOPelicula& obj) {
    if (this != &obj) { // Evitar auto-asignación
        _titol = obj._titol;
        _descripcio = obj._descripcio;
        _qualificacio = obj._qualificacio;
        _data = obj._data;
        _duracio = obj._duracio;
        _tipus = obj._tipus;
        _visGlobals = obj._visGlobals;
        _subscripcio = obj._subscripcio;
    }
    return *this;
}
